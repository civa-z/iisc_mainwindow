/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Scene;
    QRadioButton *radioButton_Face;
    QPushButton *openButton;
    QPushButton *computeButton;
    QLabel *label;
    QListWidget *imgWidget;
    QLabel *label_2;
    QListWidget *resWidget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_Alignment;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(839, 490);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_Scene = new QRadioButton(centralWidget);
        radioButton_Scene->setObjectName(QString::fromUtf8("radioButton_Scene"));
        radioButton_Scene->setChecked(true);

        horizontalLayout->addWidget(radioButton_Scene);

        radioButton_Face = new QRadioButton(centralWidget);
        radioButton_Face->setObjectName(QString::fromUtf8("radioButton_Face"));

        horizontalLayout->addWidget(radioButton_Face);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        gridLayout_2->addWidget(openButton, 1, 0, 1, 1);

        computeButton = new QPushButton(centralWidget);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));

        gridLayout_2->addWidget(computeButton, 1, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        imgWidget = new QListWidget(centralWidget);
        imgWidget->setObjectName(QString::fromUtf8("imgWidget"));

        gridLayout_2->addWidget(imgWidget, 3, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 1, 1, 1);

        resWidget = new QListWidget(centralWidget);
        resWidget->setObjectName(QString::fromUtf8("resWidget"));

        gridLayout_2->addWidget(resWidget, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_Alignment = new QRadioButton(centralWidget);
        radioButton_Alignment->setObjectName(QString::fromUtf8("radioButton_Alignment"));

        horizontalLayout_2->addWidget(radioButton_Alignment);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 839, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        radioButton_Scene->setText(QApplication::translate("MainWindow", "Scene", 0, QApplication::UnicodeUTF8));
        radioButton_Face->setText(QApplication::translate("MainWindow", "Face", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        computeButton->setText(QApplication::translate("MainWindow", "Compute", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Selected Files", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Result", 0, QApplication::UnicodeUTF8));
        radioButton_Alignment->setText(QApplication::translate("MainWindow", "Alignment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
