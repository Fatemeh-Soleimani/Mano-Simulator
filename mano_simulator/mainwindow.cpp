#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QAction"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(" Mano Simulator");
    setWindowIcon(QIcon(":/icon/icon-bg/icon1.png"));
    ui->compile_pbtn->setIcon(QIcon(":/icon/icon-bg/administration.png"));
    ui->reset_pbtn->setIcon(QIcon(":/icon/icon-bg/circular.png"));
    ui->run_pbtn->setIcon(QIcon(":/icon/icon-bg/play-button.png"));
    ui->next_pbtn->setIcon(QIcon(":/icon/icon-bg/next.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

}


void MainWindow::on_actionOpen_triggered()
{

}


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_actionSave_As_triggered()
{

}


void MainWindow::on_actionCompile_triggered()
{

}


void MainWindow::on_actionRun_triggered()
{

}

