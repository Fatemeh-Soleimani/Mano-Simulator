/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionCompile;
    QAction *actionRun;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QPushButton *compile_pbtn;
    QPushButton *next_pbtn;
    QPushButton *run_pbtn;
    QPushButton *reset_pbtn;
    QLabel *label_21;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_16;
    QLineEdit *lineEdit_16;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_15;
    QLineEdit *lineEdit_15;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_13;
    QLineEdit *lineEdit_13;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_14;
    QLineEdit *lineEdit_14;
    QHBoxLayout *horizontalLayout_19;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_17;
    QLineEdit *lineEdit_17;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_19;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_20;
    QTableWidget *tableWidget;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_18;
    QLineEdit *lineEdit_18;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAssemble;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1013, 693);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 52, 91);\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font: 75 10pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 207, 67);\n"
"gridline-color: rgb(92, 224, 216);\n"
"border-color: rgb(92, 224, 216);"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon-bg/new-file.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon);
        actionNew->setShortcutContext(Qt::WindowShortcut);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon-bg/open.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/icon-bg/diskette.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/icon-bg/save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_As->setIcon(icon3);
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/icon-bg/record.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCompile->setIcon(icon4);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/icon-bg/play-button.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRun->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 241, 571));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 188);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(260, 40, 481, 65));
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_5 = new QLineEdit(frame);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_6->addWidget(lineEdit_5);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_6 = new QLineEdit(frame);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        lineEdit_7 = new QLineEdit(frame);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_8->addWidget(lineEdit_7);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_9);

        compile_pbtn = new QPushButton(centralwidget);
        compile_pbtn->setObjectName(QString::fromUtf8("compile_pbtn"));
        compile_pbtn->setGeometry(QRect(760, 340, 211, 61));
        compile_pbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 207, 67);\n"
"\n"
"color: rgb(0, 0, 0);"));
        next_pbtn = new QPushButton(centralwidget);
        next_pbtn->setObjectName(QString::fromUtf8("next_pbtn"));
        next_pbtn->setGeometry(QRect(760, 410, 211, 61));
        next_pbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(92, 224, 216);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"MS Shell Dlg 2\";"));
        run_pbtn = new QPushButton(centralwidget);
        run_pbtn->setObjectName(QString::fromUtf8("run_pbtn"));
        run_pbtn->setGeometry(QRect(760, 480, 211, 61));
        run_pbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 207, 67);\n"
"color: rgb(0, 0, 0);"));
        reset_pbtn = new QPushButton(centralwidget);
        reset_pbtn->setObjectName(QString::fromUtf8("reset_pbtn"));
        reset_pbtn->setGeometry(QRect(760, 550, 211, 61));
        reset_pbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(92, 224, 216);\n"
"color: rgb(0, 0, 0);"));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 20, 55, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 190, 281, 33));
        horizontalLayout_23 = new QHBoxLayout(layoutWidget);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(92, 224, 216);"));

        horizontalLayout_20->addWidget(label_16);

        lineEdit_16 = new QLineEdit(layoutWidget);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));

        horizontalLayout_20->addWidget(lineEdit_16);


        horizontalLayout_23->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(92, 224, 216);"));

        horizontalLayout_21->addWidget(label_15);

        lineEdit_15 = new QLineEdit(layoutWidget);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        horizontalLayout_21->addWidget(lineEdit_15);


        horizontalLayout_23->addLayout(horizontalLayout_21);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(272, 110, 313, 75));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(92, 224, 216);"));

        horizontalLayout_10->addWidget(label_8);

        lineEdit_8 = new QLineEdit(layoutWidget1);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_10->addWidget(lineEdit_8);


        horizontalLayout_14->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(92, 224, 216);"));

        horizontalLayout_11->addWidget(label_9);

        lineEdit_9 = new QLineEdit(layoutWidget1);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_11->addWidget(lineEdit_9);


        horizontalLayout_14->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(92, 224, 216);"));

        horizontalLayout_12->addWidget(label_10);

        lineEdit_10 = new QLineEdit(layoutWidget1);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        horizontalLayout_12->addWidget(lineEdit_10);


        horizontalLayout_14->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(92, 224, 216);"));

        horizontalLayout_13->addWidget(label_11);

        lineEdit_11 = new QLineEdit(layoutWidget1);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        horizontalLayout_13->addWidget(lineEdit_11);


        horizontalLayout_14->addLayout(horizontalLayout_13);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_16->addWidget(label_12);

        lineEdit_12 = new QLineEdit(layoutWidget1);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        horizontalLayout_16->addWidget(lineEdit_12);


        horizontalLayout_15->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_17->addWidget(label_13);

        lineEdit_13 = new QLineEdit(layoutWidget1);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout_17->addWidget(lineEdit_13);


        horizontalLayout_15->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_18->addWidget(label_14);

        lineEdit_14 = new QLineEdit(layoutWidget1);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setStyleSheet(QString::fromUtf8("border-color: rgb(92, 224, 216);"));

        horizontalLayout_18->addWidget(lineEdit_14);


        horizontalLayout_15->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));

        horizontalLayout_15->addLayout(horizontalLayout_19);


        verticalLayout_3->addLayout(horizontalLayout_15);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(600, 190, 131, 31));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(92, 224, 216);"));

        horizontalLayout_22->addWidget(label_17);

        lineEdit_17 = new QLineEdit(layoutWidget2);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));

        horizontalLayout_22->addWidget(lineEdit_17);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(760, 120, 211, 207));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_5->addWidget(label_19);

        textBrowser = new QTextBrowser(layoutWidget3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 188);"));

        verticalLayout_5->addWidget(textBrowser);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(260, 240, 481, 371));
        verticalLayout_6 = new QVBoxLayout(layoutWidget4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_6->addWidget(label_20);

        tableWidget = new QTableWidget(layoutWidget4);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 224, 220);\n"
"color: rgb(0, 0, 0);"));
        tableWidget->setAlternatingRowColors(true);

        verticalLayout_6->addWidget(tableWidget);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(760, 40, 211, 59));
        verticalLayout_4 = new QVBoxLayout(layoutWidget5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_4->addWidget(label_18);

        lineEdit_18 = new QLineEdit(layoutWidget5);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 188);"));

        verticalLayout_4->addWidget(lineEdit_18);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1013, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAssemble = new QMenu(menubar);
        menuAssemble->setObjectName(QString::fromUtf8("menuAssemble"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAssemble->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuAssemble->addAction(actionCompile);
        menuAssemble->addAction(actionRun);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionCompile->setText(QCoreApplication::translate("MainWindow", "Compile", nullptr));
        actionRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "SC:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PC:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "AR:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "IR:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "DR:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "AC:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TR:", nullptr));
        compile_pbtn->setText(QCoreApplication::translate("MainWindow", "Compile", nullptr));
        next_pbtn->setText(QCoreApplication::translate("MainWindow", "next step", nullptr));
        run_pbtn->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        reset_pbtn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "code:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "OUTR:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "INPR:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "I:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "S:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "E:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "R:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "IEN:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "FGI:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "FGO:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "input:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Console:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "RAM:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Label", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Instruction", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Microoperation:", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAssemble->setTitle(QCoreApplication::translate("MainWindow", "Assemble", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
