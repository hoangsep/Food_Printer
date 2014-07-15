/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *currentFileName;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveButton;
    QPushButton *saveAsButton;
    QPushButton *discardButton;
    QGridLayout *gridLayout;
    QLabel *endingRatio2Label;
    QSpinBox *endingRatio2;
    QSpinBox *startingRatio3;
    QSpinBox *endingRatio1;
    QLabel *endingRatio1Label;
    QLabel *startingRatio1Label;
    QSpinBox *startingRatio1;
    QSpinBox *endingRatio3;
    QLabel *startingRatio2Label;
    QSpinBox *startingRatio2;
    QLabel *startingratio3Label;
    QLabel *endingRatio3Label;
    QHBoxLayout *horizontalLayout;
    QLabel *origGCodeLabel;
    QComboBox *origGCodeComboBox;
    QPushButton *origGCodeLocation;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mixedGCodeLabel;
    QComboBox *mixedGCodeCcomboBox;
    QPushButton *mixedGCodeLocation;
    QPushButton *mixButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(934, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setEnabled(true);
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 914, 427));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        currentFileName = new QLabel(scrollAreaWidgetContents);
        currentFileName->setObjectName(QStringLiteral("currentFileName"));
        currentFileName->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout_2->addWidget(currentFileName);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_4->addWidget(textEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        saveButton = new QPushButton(scrollAreaWidgetContents);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setCheckable(false);

        horizontalLayout_3->addWidget(saveButton);

        saveAsButton = new QPushButton(scrollAreaWidgetContents);
        saveAsButton->setObjectName(QStringLiteral("saveAsButton"));

        horizontalLayout_3->addWidget(saveAsButton);

        discardButton = new QPushButton(scrollAreaWidgetContents);
        discardButton->setObjectName(QStringLiteral("discardButton"));

        horizontalLayout_3->addWidget(discardButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        endingRatio2Label = new QLabel(scrollAreaWidgetContents);
        endingRatio2Label->setObjectName(QStringLiteral("endingRatio2Label"));

        gridLayout->addWidget(endingRatio2Label, 1, 2, 1, 1);

        endingRatio2 = new QSpinBox(scrollAreaWidgetContents);
        endingRatio2->setObjectName(QStringLiteral("endingRatio2"));

        gridLayout->addWidget(endingRatio2, 1, 3, 1, 1);

        startingRatio3 = new QSpinBox(scrollAreaWidgetContents);
        startingRatio3->setObjectName(QStringLiteral("startingRatio3"));

        gridLayout->addWidget(startingRatio3, 0, 5, 1, 1);

        endingRatio1 = new QSpinBox(scrollAreaWidgetContents);
        endingRatio1->setObjectName(QStringLiteral("endingRatio1"));

        gridLayout->addWidget(endingRatio1, 1, 1, 1, 1);

        endingRatio1Label = new QLabel(scrollAreaWidgetContents);
        endingRatio1Label->setObjectName(QStringLiteral("endingRatio1Label"));

        gridLayout->addWidget(endingRatio1Label, 1, 0, 1, 1);

        startingRatio1Label = new QLabel(scrollAreaWidgetContents);
        startingRatio1Label->setObjectName(QStringLiteral("startingRatio1Label"));

        gridLayout->addWidget(startingRatio1Label, 0, 0, 1, 1);

        startingRatio1 = new QSpinBox(scrollAreaWidgetContents);
        startingRatio1->setObjectName(QStringLiteral("startingRatio1"));

        gridLayout->addWidget(startingRatio1, 0, 1, 1, 1);

        endingRatio3 = new QSpinBox(scrollAreaWidgetContents);
        endingRatio3->setObjectName(QStringLiteral("endingRatio3"));

        gridLayout->addWidget(endingRatio3, 1, 5, 1, 1);

        startingRatio2Label = new QLabel(scrollAreaWidgetContents);
        startingRatio2Label->setObjectName(QStringLiteral("startingRatio2Label"));

        gridLayout->addWidget(startingRatio2Label, 0, 2, 1, 1);

        startingRatio2 = new QSpinBox(scrollAreaWidgetContents);
        startingRatio2->setObjectName(QStringLiteral("startingRatio2"));

        gridLayout->addWidget(startingRatio2, 0, 3, 1, 1);

        startingratio3Label = new QLabel(scrollAreaWidgetContents);
        startingratio3Label->setObjectName(QStringLiteral("startingratio3Label"));

        gridLayout->addWidget(startingratio3Label, 0, 4, 1, 1);

        endingRatio3Label = new QLabel(scrollAreaWidgetContents);
        endingRatio3Label->setObjectName(QStringLiteral("endingRatio3Label"));

        gridLayout->addWidget(endingRatio3Label, 1, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        origGCodeLabel = new QLabel(scrollAreaWidgetContents);
        origGCodeLabel->setObjectName(QStringLiteral("origGCodeLabel"));

        horizontalLayout->addWidget(origGCodeLabel);

        origGCodeComboBox = new QComboBox(scrollAreaWidgetContents);
        origGCodeComboBox->setObjectName(QStringLiteral("origGCodeComboBox"));
        origGCodeComboBox->setMinimumSize(QSize(700, 0));

        horizontalLayout->addWidget(origGCodeComboBox);

        origGCodeLocation = new QPushButton(scrollAreaWidgetContents);
        origGCodeLocation->setObjectName(QStringLiteral("origGCodeLocation"));

        horizontalLayout->addWidget(origGCodeLocation);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mixedGCodeLabel = new QLabel(scrollAreaWidgetContents);
        mixedGCodeLabel->setObjectName(QStringLiteral("mixedGCodeLabel"));

        horizontalLayout_2->addWidget(mixedGCodeLabel);

        mixedGCodeCcomboBox = new QComboBox(scrollAreaWidgetContents);
        mixedGCodeCcomboBox->setObjectName(QStringLiteral("mixedGCodeCcomboBox"));
        mixedGCodeCcomboBox->setMinimumSize(QSize(700, 0));

        horizontalLayout_2->addWidget(mixedGCodeCcomboBox);

        mixedGCodeLocation = new QPushButton(scrollAreaWidgetContents);
        mixedGCodeLocation->setObjectName(QStringLiteral("mixedGCodeLocation"));

        horizontalLayout_2->addWidget(mixedGCodeLocation);


        verticalLayout_2->addLayout(horizontalLayout_2);

        mixButton = new QPushButton(scrollAreaWidgetContents);
        mixButton->setObjectName(QStringLiteral("mixButton"));
        mixButton->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(mixButton);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 934, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        currentFileName->setText(QApplication::translate("MainWindow", "Current Processing File", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        saveAsButton->setText(QApplication::translate("MainWindow", "Save As", 0));
        discardButton->setText(QApplication::translate("MainWindow", "Discard", 0));
        discardButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        endingRatio2Label->setText(QApplication::translate("MainWindow", "Ending Ratio 2", 0));
        endingRatio1Label->setText(QApplication::translate("MainWindow", "Ending Ratio 1", 0));
        startingRatio1Label->setText(QApplication::translate("MainWindow", "Starting Ratio 1", 0));
        startingRatio2Label->setText(QApplication::translate("MainWindow", "Starting Ratio 2", 0));
        startingratio3Label->setText(QApplication::translate("MainWindow", "Starting Ratio 3", 0));
        endingRatio3Label->setText(QApplication::translate("MainWindow", "Ending Ratio 3", 0));
        origGCodeLabel->setText(QApplication::translate("MainWindow", "Original GCode", 0));
        origGCodeLocation->setText(QApplication::translate("MainWindow", "Browse", 0));
        mixedGCodeLabel->setText(QApplication::translate("MainWindow", "   Mixed Gcode", 0));
        mixedGCodeLocation->setText(QApplication::translate("MainWindow", "Browse", 0));
        mixButton->setText(QApplication::translate("MainWindow", "MIX IT", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
