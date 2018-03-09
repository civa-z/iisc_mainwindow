#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QtGui/QButtonGroup>
#include <iostream>


#include "imagefilter.h"
#include "imagefilter_hash.h"
#include "imagefilter_hash_face.h"
#include "imagefilter_alignment_face.h"


extern QStringList fileNames;
using namespace std;
extern vector<double> computeSimilarity_PSNR();
extern vector<vector<double>> computeSimilarity_HASH();
extern vector<double> computeSimilarity_OSTU();
extern double computeThreshold(vector<double> similarity);
extern vector<int> getPictures(vector<vector<double>> distance);
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked();
    void on_computeButton_clicked();

private:
    Ui::MainWindow *ui;

private:
    void deleteAllItems();
    std::string getFileName(std::string path);
    void showOnePic(QString path, int nIndex);
    void showOneRes(QString path, int nIndex);
	QPixmap getPicFromFile(std::string path);
    QAction *openAction;
	QButtonGroup* qButtonGroup;
    int iconWidth;
    int iconHeight;

	std::string getFilterType();
	ImageFilterHash imagefilter_hash;
	FaceImageFilter imagefilter_hash_face;
	ImageFilterAlignmentFace imagefilter_alignment;
};

#endif // MAINWINDOW_H
