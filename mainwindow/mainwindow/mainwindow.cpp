#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAction>
#include <iostream>
#include <algorithm>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iconWidth = ui->imgWidget->width() / 2;
    iconHeight = ui->imgWidget->height() / 2;
    iconWidth = 96;
    iconHeight = 96;
    ui->imgWidget->setIconSize(QSize(iconWidth, iconHeight));
    ui->imgWidget->setResizeMode(QListView::Adjust);
    ui->imgWidget->setViewMode(QListView::IconMode);
    ui->imgWidget->setMovement(QListView::Static);
    ui->imgWidget->setSpacing(10);

    ui->resWidget->setIconSize(QSize(iconWidth, iconHeight));
    ui->resWidget->setResizeMode(QListView::Adjust);
    ui->resWidget->setViewMode(QListView::IconMode);
    ui->resWidget->setMovement(QListView::Static);
    ui->resWidget->setSpacing(10);

	qButtonGroup = new QButtonGroup(this);
	qButtonGroup->addButton(ui->radioButton_Scene, 1);
    qButtonGroup->addButton(ui->radioButton_Face, 2);
    qButtonGroup->addButton(ui->radioButton_Alignment, 3);
}

MainWindow::~MainWindow()
{
	delete qButtonGroup;
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    deleteAllItems();
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("´ò¿ªÍ¼Æ¬"));
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    fileDialog->close();
    int nIndex = 0;
	for (int i = 0; i < fileNames.size(); ++i) {
        showOnePic(fileNames[i], nIndex);
        nIndex++;
    }
}

QPixmap MainWindow::getPicFromFile(std::string path){
	cv::Mat mat = cv::imread(path);
	QImage qimg;
	cv::Mat rgb;
	if(mat.channels() == 3)    // RGB image  
	{  
		cv::cvtColor(mat,rgb,CV_BGR2RGB);  
		qimg = QImage((const uchar*)(rgb.data),  //(const unsigned char*)  
						rgb.cols,rgb.rows,  
						rgb.cols*rgb.channels(),   //new add  
						QImage::Format_RGB888);  
	}else                     // gray image  
	{  
		qimg = QImage((const uchar*)(mat.data),  
						mat.cols, mat.rows,  
						mat.cols * mat.channels(),    //new add  
						QImage::Format_Indexed8);  
	}
	QPixmap img = QPixmap::fromImage(qimg);
	return img;
}

/*Display one pic to front-end*/
void MainWindow::showOnePic(QString path, int nIndex) {
    //QPixmap img(path);
	QPixmap img = getPicFromFile(path.toStdString());
	std::cout<<"Path:"<<path.toStdString()<<std::endl<<std::flush;
    double ratio = max(img.width(), img.height()) / (iconWidth);
    int itemWidth = img.width() / ratio;
    int itemHeight = img.height() / ratio;

    QListWidgetItem *pItem = new QListWidgetItem(ui->imgWidget);
    pItem->setIcon(QIcon(img.scaled(QSize(itemWidth,itemHeight))));
    string spath = path.toStdString();
    string name = getFileName(spath);
    pItem->setText(QString::fromStdString(name));
    pItem->setTextAlignment(Qt::AlignHCenter);
    pItem->setSizeHint(QSize(iconWidth,iconHeight));
    ui->imgWidget->insertItem(nIndex, pItem);
}
/*Display one result to front-end*/
void MainWindow::showOneRes(QString path, int nIndex) {
    //QPixmap img(path);
	QPixmap img = getPicFromFile(path.toStdString());
    double ratio = max(img.width(), img.height()) / (iconWidth);
    int itemWidth = img.width() / ratio;
    int itemHeight = img.height() / ratio;

    QListWidgetItem *pItem = new QListWidgetItem(ui->resWidget);
    pItem->setIcon(QIcon(img.scaled(QSize(itemWidth,itemHeight))));
    string spath = path.toStdString();
    string name = getFileName(spath);
    pItem->setText(QString::fromStdString(name));
    pItem->setTextAlignment(Qt::AlignHCenter);
    pItem->setSizeHint(QSize(iconWidth,iconHeight));
    ui->resWidget->insertItem(nIndex, pItem);
}

/*delete all loaded image files each time 'open' gets clicked*/
void MainWindow::deleteAllItems() {
    ui->imgWidget->clear();
    ui->resWidget->clear();
}

string MainWindow::getFileName(string path) {
    int begin = path.rfind("/");
    int end = path.rfind(".");
    return path.substr(begin + 1, end - begin - 1);
}

std::string MainWindow::getFilterType(){
	if (ui->radioButton_Scene->isChecked())
		return "Scene";
	if (ui->radioButton_Face->isChecked())
		return "Face";
	if (ui->radioButton_Alignment->isChecked())
		return "Alignment";
	return "Other";
}

void MainWindow::on_computeButton_clicked()
{
	ui->resWidget->clear();
	string filterType = getFilterType();
	std::vector<std::string> fileList;
	for (int i = 0; i < fileNames.size(); ++i) {
		fileList.push_back(fileNames[i].toStdString());
	}
	if (fileList.size() == 0)
		return;

	vector<vector<double>> similarity;
	std::cout<<"filterType: "<<filterType<<std::endl<<std::fflush;
	if (filterType.compare("Face") == 0){
		std::cout<<std::endl<<"Start Face"<<std::endl<<std::fflush;
		imagefilter_hash_face.loadFaceRecognizer(".\\data\\FA\\");
		imagefilter_hash_face.setFileList(fileList);
		similarity = imagefilter_hash_face.computeSimilarity();
	} else if (filterType.compare("Alignment") == 0){
		imagefilter_alignment.loadFaceRecognizer(".\\data\\FA\\");
		imagefilter_alignment.setFileList(fileList);
		similarity = imagefilter_alignment.computeSimilarity();
	} else {
		similarity = computeSimilarity_HASH();
	}

    int nIndex = 0;
    vector<int> result = getPictures(similarity);
    for (int i = 0; i < result.size(); ++i) {
        showOneRes(fileNames[result[i]], nIndex);
        nIndex++;
    }
}
