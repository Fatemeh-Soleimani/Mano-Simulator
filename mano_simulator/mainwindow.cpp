#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QAction"
#include<QFileDialog>
#include<fstream>
#include<QFile>
#include<QMessageBox>
#include<sstream>
#include <ctype.h>
#include<QtDebug>
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
    ui->code_txtedit->setFocus();
    on_reset_btn_clicked();

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
void MainWindow::on_reset_btn_clicked()
{
    reseter=1;
    SC.reset();
    PC.reset();
    AR.reset();
    IR.reset();
    DR.reset();
    AC.reset();
    TR.reset();
    INPR.reset();
    OUTR.reset();
    I.reset();
    S.reset();
    E.reset();
    R.reset();
    IEN.reset();
    FGI.reset();
    FGO.reset();
    resetRam();
    printTable();
    printReg();
    ui->console_txt->setText("");
    allDatas.clear();
    firstallDatas.clear();
    commands.clear();
    compiled=0;
    clk=0;
    lineStep=0;
    memorystep=0;
    run=0;
    printing=1;
    ui->run_pbtn->setEnabled(true);
    ui->next_pbtn->setEnabled(true);
    ui->input_lineedit->setText("");
    ui->ope_line->setText("");
    memoryToLine.clear();




}
void MainWindow::printReg()
{
    ui->SC_lineedit->setText(QString::number( SC.to_ulong(), 16 ).toUpper());
    ui->PC_lineedit->setText(QString::number( PC.to_ulong(), 16 ).toUpper());
    ui->AR_lineedit->setText(QString::number( AR.to_ulong(), 16 ).toUpper());
    ui->IR_lineedit->setText(QString::number( IR.to_ulong(), 16 ).toUpper());
    ui->DR_lineedit->setText(QString::number( DR.to_ulong(), 16 ).toUpper());
    ui->AC_lineedit->setText(QString::number( AC.to_ulong(), 16 ).toUpper());
    ui->TR_lineedit->setText(QString::number( TR.to_ulong(), 16 ).toUpper());
    ui->INPR_lineedit->setText(QString::number( INPR.to_ulong(), 16 ).toUpper());
    ui->OUTR_lineedit->setText(QString::number( OUTR.to_ulong(), 16 ).toUpper());
    ui->I_lineedit->setText(QString::number( I.to_ulong(), 16 ).toUpper());
    ui->S_lineedit->setText(QString::number( S.to_ulong(), 16 ).toUpper());
    ui->E_lineedit->setText(QString::number( E.to_ulong(), 16 ).toUpper());
    ui->R_lineedit->setText(QString::number( R.to_ulong(), 16 ).toUpper());
    ui->IE_lineedit->setText(QString::number( IEN.to_ulong(), 16 ).toUpper());
    ui->FGI_lineedit->setText(QString::number( FGI.to_ulong(), 16 ).toUpper());
    ui->FGO_lineedit->setText(QString::number( FGO.to_ulong(), 16 ).toUpper());

}

void MainWindow::printTable()
{
    if(reseter)
    {
        ui->RAM->setRowCount(0);
        for(int i=0;i<4096;i++)
        {
            QString address = QString::number( i, 16 ).toUpper();
            QTableWidgetItem *itmaddr = new QTableWidgetItem();
            QTableWidgetItem *itmHex = new QTableWidgetItem();
            itmaddr->setText(address);
            itmHex->setText("0000");
            ui->RAM->insertRow(i);
            ui->RAM->setItem(i,1,itmaddr);
            ui->RAM->setItem(i,3,itmHex);
            reseter=0;
        }
    }
    else
    {
        for(int i=0;i<4096;i++)
        {
            QString address = QString::number( i, 16 ).toUpper();
            QTableWidgetItem *itmaddr = new QTableWidgetItem();
            QTableWidgetItem *itmHex = new QTableWidgetItem();
            itmaddr->setText(address);
            QString checkerString =QString::number( ram[i].to_ulong(), 16 ).toUpper();
            if(checkerString.size()==3){
                checkerString = "0" + checkerString;
            }
            else if(checkerString.size()==2){
                checkerString = "00" + checkerString;
            }
            else if(checkerString.size()==1){
                checkerString = "000" + checkerString;
            }
            itmHex->setText(checkerString);
            ui->RAM->setItem(i,1,itmaddr);
            ui->RAM->setItem(i,3,itmHex);

        }
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

