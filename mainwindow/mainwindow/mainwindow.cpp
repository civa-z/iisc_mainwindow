#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAction>
#include <iostream>
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
}

MainWindow::~MainWindow()
{
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

/*Display one pic to front-end*/
void MainWindow::showOnePic(QString path, int nIndex) {
    QPixmap img(path);
    double ratio = std::max(img.width(), img.height()) / (iconWidth);
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
    QPixmap img(path);
    double ratio = std::max(img.width(), img.height()) / (iconWidth);
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

void MainWindow::on_computeButton_clicked()
{
    vector<vector<double>> similarity = computeSimilarity_HASH();
    int nIndex = 0;
    vector<int> result = getPictures(similarity);
    for (int i = 0; i < result.size(); ++i) {
        showOneRes(fileNames[result[i]], nIndex);
        nIndex++;
    }
}
