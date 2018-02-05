#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <iostream>
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
    QAction *openAction;
    QListWidget *m_pListWidget;
    int iconWidth;
    int iconHeight;
};

#endif // MAINWINDOW_H
