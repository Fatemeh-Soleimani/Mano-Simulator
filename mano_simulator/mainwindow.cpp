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

//quint16 : Typedef for unsigned short. This type is guaranteed to be 16-bit on all platforms supported by Qt.
quint16 MainWindow::getE() { return E.to_ulong(); }
quint16 MainWindow::getDR() { return DR.to_ulong(); }
quint16 MainWindow::getAC() { return AC.to_ulong(); }
bool MainWindow::getACleadingBit() { return AC[15]; }
quint16 MainWindow::getIR() { return IR.to_ulong(); }
quint16 MainWindow::getTR() { return TR.to_ulong(); }
quint16 MainWindow::getAR() { return AR.to_ulong(); }
quint16 MainWindow::getPC() { return PC.to_ulong(); }
quint16 MainWindow::getINPR() { return INPR.to_ulong(); }
quint16 MainWindow::getOUTR() { return OUTR.to_ulong(); }


void MainWindow::setE(const quint16& E) { this->E = std::bitset<1>(E); }
void MainWindow::setDR(const quint16& DR) { this->DR = std::bitset<16>(DR); }
void MainWindow::setAC(const quint16& AC) { this->AC = std::bitset<16>(AC); }
void MainWindow::setIR(const quint16& IR) { this->IR = std::bitset<16>(IR); }
void MainWindow::setTR(const quint16& TR) { this->TR = std::bitset<16>(TR); }
void MainWindow::setAR(const quint16& AR) { this->AR = std::bitset<12>(AR); }
void MainWindow::setPC(const quint16& PC) { this->PC = std::bitset<12>(PC); }
void MainWindow::setINPR(const quint8& INPR) { this->INPR = std::bitset<8>(INPR); }
void MainWindow::setOUTR(const quint8& OUTR) { this->OUTR = std::bitset<8>(OUTR); }

//edit inr to inc
void MainWindow::incAR() { setAR(getAR() + 1); }
void MainWindow::incPC() { setPC(getPC() + 1); }
void MainWindow::incDR() { setDR(getDR() + 1); }
void MainWindow::incAC() { setAC(getAC() + 1); }
void MainWindow::incTR() { setTR(getTR() + 1); }

void MainWindow::clrAR() { AR.reset(); }
void MainWindow::clrPC() { PC.reset(); }
void MainWindow::clrDR() { DR.reset(); }
void MainWindow::clrAC() { AC.reset(); }
void MainWindow::clrTR() { TR.reset(); }

void MainWindow::logicUnitAND(){ AC = AC & DR; }
void MainWindow::logicUnitCMA() { AC = ~AC; }

//??
void MainWindow::emptyTable()
{
    for(int i=0;i<4096;i++)
    {
        //number : Returns a string equivalent of the number n according to the specified base.
        QString result = QString::number( i, 16 ).toUpper();
        //??
        QTableWidgetItem *itm = new QTableWidgetItem();
        QTableWidgetItem *empty = new QTableWidgetItem();
        itm->setText(result);
        empty->setText("0000");
        //ram_tb->RAM
        ui->RAM->insertRow(i);
        ui->RAM->setItem(i,1,itm);
        ui->RAM->setItem(i,3,empty);

    }
}

void MainWindow::resetRam()
{
    for(int i=0;i<4096;i++)
    {
        ram[i].reset();
    }
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

