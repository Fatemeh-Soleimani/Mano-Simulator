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

//???
void MainWindow::arithmeticUnitADD()
{
    std::bitset<1> c(0);
    std::bitset<16> sum(0);

    for(quint16 i = 0; i < AC.size(); i++){
        sum[i] = AC[i] ^ DR[i] ^ c[0];
        //to_ulong : cast to convert it to int ???? warning
        c = c[0] & (AC[i] ^ DR[i]) | (AC[i] & DR[i]);
    }

    E = c;
    AC = sum;
}

void MainWindow::arithmeticUnitCIR() {
    E[0] = AC[0];
    AC = AC >> 1;
    AC[15] = E[0];
}


void MainWindow::arithmeticUnitCIL() {
    E[0] = AC[15];
    AC = AC << 1;
    AC[0] = E[0];
}

bool MainWindow::isNumber(const QString &str)
{
    string check=str.toStdString();
    //iterator ??? simple for
    for (char const &c : check)
    {
        if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f'|| c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F'|| c=='-' || c=='+')
        {
            continue;
        }
        if (isdigit(c) == 0) return false;
    }
       return true;
}

void MainWindow::on_compile_btn_clicked()
{
    on_reset_btn_clicked();
    compiled=1;
    int lc=0;
    int lc1=0;
    ui->console_txt->setText("");
    commands = ui->code_txtedit->toPlainText().split('\n', Qt::SkipEmptyParts);
    tcommmands=commands.size();
    int endp1=0;


    for(int i=0;i<tcommmands;i++)
    {
        if(lc>4096)
        {
            ui->console_txt->setText("ERROR: OVERFLOW RAM!\n");
            compiled=0;
            break;
        }
        QStringList riz = commands.at(i).split(' ', Qt::SkipEmptyParts);
        if(riz.at(0)[riz.at(0).size()-1]==',')
        {
            QString wait="";
            for(int cw=0;cw<riz.at(0).size()-1;cw++)
            {
                wait+=riz.at(0)[cw];
            }
            firstallDatas[wait]=lc1;
        }
        else if(riz.at(0)=="ORG")
        {
            if(isNumber(riz.at(1)))
            {
                bool ok=1;
                lc1=riz.at(1).toInt(&ok,16);
                continue;

            }
            else
            {
                ui->console_txt->setText("error in line:"+QString::number(i+1)+"\n You need hex number after ORG. \n");
                compiled=0;
                break;
            }
        }


        memoryToLine[lc1]=i;
        //qDebug()<<"memory: "<<lc1 <<"  ,,,  " <<"line :"<<i;
        lc1++;

    }



    for(int i=0;i<tcommmands; i++, lc++)
    {
        //more than ram's capacity
        if(lc>4096)
        {
            ui->console_txt->setText("ERROR: OVERFLOW RAM!\n");
            compiled=0;
            break;
        }
        //each lines

        QStringList riz = commands.at(i).split(' ', Qt::SkipEmptyParts);

        //?? delete if (not neccessary)
            //each words
            if(riz.at(0)=="//" || riz.at(0)[0]=='/')
            {
                //comment
                //ui->console->setText("comment in line:"+QString::number(i+1)+"\n");
                continue;
            }
            else if(riz.at(0)=="ORG")
            {
                if(isNumber(riz.at(1)))
                {
                    bool ok=1;
                    lc=riz.at(1).toInt(&ok,16);
                    continue;

                }
                else
                {
                    ui->console_txt->setText("error in line:"+QString::number(i+1)+"\n You need hex number after ORG. \n");
                    compiled=0;
                    break;
                }
            }

            else if(riz.at(0)[riz.at(0).size()-1]==',')
            {
                allDatas[riz.at(0)]=i;
                QTableWidgetItem *itmlabel = new QTableWidgetItem();
                itmlabel->setText(riz.at(0));
                ui->RAM->setItem(lc,0,itmlabel);
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                int convertNumber;
                if(riz.at(1)=="HEX")
                {
                    if(isNumber(riz.at(2)))
                    {
                        bool ok=1;
                        convertNumber=riz.at(2).toInt(&ok,16);
                        ram[lc]=convertNumber;
                        lc++;
                        continue;
                    }
                    else
                    {
                        ui->console_txt->setText("error in line:"+QString::number(i+1)+"\n You need valid number after HEX. \n");
                        compiled=0;
                        break;
                    }
                }
                else if(riz.at(1)=="DEC")
                {
                    if(isNumber(riz.at(2)))
                    {
                        bool ok=1;
                        convertNumber=riz.at(2).toInt(&ok,10);
                        ram[lc]=convertNumber;
                        lc++;
                        continue;
                    }
                    else
                    {
                        ui->console_txt->setText("error in line:"+QString::number(i+1)+"\n You need valid number after DEC. \n");
                        compiled=0;
                        break;
                    }
                }
                else
                {

                    for(int x=0;x<(riz.length())-1;x++)
                    {
                        riz[x]=riz[x+1];
                    }
                }

            }


            if(riz.at(0)=="DEC")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(riz.length()>1 && isNumber(riz.at(1)) )
                {
                    bool ok=1;
                    int convertNumber=riz.at(1).toInt(&ok,10);
                    ram[lc]=convertNumber;
                }
                else
                {
                    ui->console_txt->setText("error in line:"+QString::number(i+1)+"\n You need valid number after DEC. \n");
                    compiled=0;
                    break;
                }

            }
            else if(riz.at(0)=="HEX")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(riz.length()>1 && isNumber(riz.at(1)))
                {
                    bool ok=1;
                    int convertNumber=riz.at(1).toInt(&ok,16);
                    ram[lc]=convertNumber;
                }
                else
                {
                    ui->console_txt->setText("error in line:"+QString::number(i+1)+"\n You need valid number after HEX. \n");
                    compiled=0;
                    break;
                }
            }




            //commands
            else if(riz.at(0)=="AND")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(firstallDatas[riz.at(1)]==0)
                {
                    ui->console_txt->setText("Error in line:"+QString::number(i+1)+"there is no label by name"+riz.at(1));
                    compiled=0;
                    break;

                }
                //indirect
                if(riz.size()>=3 && riz.at(2)=='I')
                {
                    ram[lc]=0x8000+firstallDatas[riz.at(1)];
                }
                else
                {
                    ram[lc]=0x0000+firstallDatas[riz.at(1)];
                }

            }



            else if(riz.at(0)=="ADD")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(firstallDatas[riz.at(1)]==0)
                {
                    ui->console_txt->setText("Error in line:"+QString::number(i+1)+"there is no label by name"+riz.at(1));
                    compiled=0;
                    break;

                }
                //indirect
                if(riz.size()>=3 && riz.at(2)=='I')
                {
                    ram[lc]=0x9000+firstallDatas[riz.at(1)];
                }
                else
                {
                    ram[lc]=0x1000+firstallDatas[riz.at(1)];
                }

            }




            else if(riz.at(0)=="LDA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(firstallDatas[riz.at(1)]==0)
                {
                    ui->console_txt->setText("Error in line:"+QString::number(i+1)+"there is no label by name"+riz.at(1));
                    compiled=0;
                    break;

                }
                //indirect
                if(riz.size()>=3 && riz.at(2)=='I')
                {
                    ram[lc]=0xA000+firstallDatas[riz.at(1)];
                }
                else
                {
                    ram[lc]=0x2000+firstallDatas[riz.at(1)];
                }

            }



            else if(riz.at(0)=="STA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(firstallDatas[riz.at(1)]==0)
                {
                    ui->console_txt->setText("Error in line:"+QString::number(i+1)+"there is no label by name"+riz.at(1));
                    compiled=0;
                    break;

                }
                //indirect
                if(riz.size()>=3 && riz.at(2)=='I')
                {
                    ram[lc]=0xB000+firstallDatas[riz.at(1)];
                }
                else
                {
                    ram[lc]=0x3000+firstallDatas[riz.at(1)];
                }

            }


            else if(riz.at(0)=="BUN")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(firstallDatas[riz.at(1)]==0)
                {
                    ui->console_txt->setText("Error in line:"+QString::number(i+1)+"there is no label by name"+riz.at(1));
                    compiled=0;
                    break;

                }
                //indirect
                if(riz.size()>=3 && riz.at(2)=='I')
                {
                    ram[lc]=0xC000+firstallDatas[riz.at(1)];
                }
                else
                {
                    ram[lc]=0x4000+firstallDatas[riz.at(1)];
                }

            }




            else if(riz.at(0)=="BSA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(firstallDatas[riz.at(1)]==0)
                {
                    ui->console_txt->setText("Error in line:"+QString::number(i+1)+"there is no label by name"+riz.at(1));
                    compiled=0;
                    break;

                }
                //indirect
                if(riz.size()>=3 && riz.at(2)=='I')
                {
                    ram[lc]=0xD000+firstallDatas[riz.at(1)];
                }
                else
                {
                    ram[lc]=0x5000+firstallDatas[riz.at(1)];
                }

            }


            else if(riz.at(0)=="ISZ")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                if(firstallDatas[riz.at(1)]==0)
                {
                    ui->console_txt->setText("Error in line: "+QString::number(i+1)+"there is no label by name "+riz.at(1));
                    compiled=0;
                    break;

                }
                //indirect
                if(riz.size()>=3 && riz.at(2)=='I')
                {
                    ram[lc]=0xE000+firstallDatas[riz.at(1)];
                }
                else
                {
                    ram[lc]=0x6000+firstallDatas[riz.at(1)];
                }

            }
            //  I/O
            else if(riz.at(0)=="INP")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0xf800;
            }

            else if(riz.at(0)=="OUT")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0xf400;
            }
            else if(riz.at(0)=="SKI")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0xf200;
            }
            else if(riz.at(0)=="SKO")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0xf100;
            }
            else if(riz.at(0)=="ION")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0xf080;
            }
            else if(riz.at(0)=="IOF")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0xf040;
            }

            //reg
            else if(riz.at(0)=="CLA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7800;
            }

            else if(riz.at(0)=="CLE")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7400;
            }
            else if(riz.at(0)=="CMA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7200;
            }
            else if(riz.at(0)=="CME")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7100;
            }
            else if(riz.at(0)=="CIR")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7080;
            }
            else if(riz.at(0)=="CIL")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7040;
            }
            else if(riz.at(0)=="INC")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7020;
            }
            else if(riz.at(0)=="SPA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7010;
            }
            else if(riz.at(0)=="SNA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7008;
            }
            else if(riz.at(0)=="SZA")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7004;
            }
            else if(riz.at(0)=="SZE")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7002;
            }
            else if(riz.at(0)=="HLT")
            {
                QTableWidgetItem *itmintraction = new QTableWidgetItem();
                itmintraction->setText(commands.at(i));
                ui->RAM->setItem(lc,2,itmintraction);
                ram[lc]=0x7001;
            }
            //assembly
            else if(riz.at(0)=="END")
            {
                endp1=1;
                printTable();
                if(compiled)
                {
                    ui->console_txt->setText("Compiled Successfully!\n");
                }
                else
                {
                    ui->console_txt->append("\nERROR IN COMPILING!\n");
                }
                break;
            }
            else
            {
                //bad command
                ui->console_txt->setText("error in line:"+QString::number(i+1)+"\n Bad Command. \n");
                ui->console_txt->append(commands.at(i));
                compiled=0;
                break;
            }

    }


    if(!endp1 && compiled)
    {
        ui->console_txt->setText("error in compiling \n there is no END!\n");
        compiled=0;
    }


}

void MainWindow::on_next_btn_clicked()
{
    if(!run)
    {
        printing=1;
    }
    if(!compiled)
    {
        ui->console_txt->setText("\n compile first!!!!\n");
    }

    else
    {
        ui->RAM->selectRow(memorystep-1);

        ui->console_txt->setText("");


                SC=clk;

                    QStringList riz = commands.at(lineStep).split(' ', Qt::SkipEmptyParts);


                    //comment
                    if(riz.at(0)=="//" || riz.at(0)[0]=='/')
                    {
                       lineStep++;


                    }
                    else if(riz.at(0)=="ORG")
                    {

                            bool ok=1;
                            memorystep=riz.at(1).toInt(&ok,16);
                            lineStep++;

                    }

                    riz = commands.at(lineStep).split(' ', Qt::SkipEmptyParts);




                    // fetch
                    //t0
                    if(clk==0)
                    {
                        S=1;
                        PC=memorystep;
                        AR=PC;
                        clk++;
                        SC=clk;
                        if(printing)
                        {
                            printReg();
                            printTable();
                        }

                        ui->ope_line->setText("T0 (FETCH): AR <- PC ");
                        return;
                    }

                    //t1
                    else if(clk==1)
                    {
                        incPC();
                        memorystep++;
                        IR=ram[AR.to_ulong()];
                        clk++;
                        SC=clk;
                        if(printing)
                        {
                            printReg();
                            printTable();
                        }
                        ui->ope_line->setText("T1 (FETCH):PC <- PC+1  , IR <- M[AR] ");
                        return;
                    }

                    //t2
                    else if(clk==2)
                    {
                        for (int bitC=0;bitC<12;bitC++)
                        {
                            AR[bitC]=IR[bitC];

                        }
                        I[0]=IR[15];
                        clk++;
                        ui->ope_line->setText("T2 (DECODE):AR <- IR(0-11) , I <- IR(15) ");
                        return;
                    }




                    if(riz.at(0)[riz.at(0).size()-1]==',')
                    {

                            for(int x=0;x<(riz.length())-1;x++)
                            {
                                riz[x]=riz[x+1];
                            }


                    }
                    if(riz.at(0)=="DEC")
                    {
                        clk=0;
                        lineStep++;

                    }
                    else if(riz.at(0)=="HEX")
                    {
                        clk=0;
                        lineStep++;

                    }

                    //commands
                    else if(riz.at(0)=="AND")
                    {
                        //t3
                        if(clk==3)
                        {

                            clk++;
                            if(riz.size()>=3 && riz.at(2)=='I')
                            {
                                ui->ope_line->setText("AR <- M[AR] ");
                                bitset<12> tmpAR=AR;
                                for (int bitC=0;bitC<12;bitC++)
                                {
                                    AR[bitC]=ram[tmpAR.to_ulong()][bitC];

                                }

                            }
                            else
                            {

                            }
                        }


                        //t4
                        else if (clk==4) {
                            ui->ope_line->setText("DR <- M[AR]");
                            clk++;
                            DR=ram[AR.to_ulong()];
                        }

                        //t5
                        else if (clk==5) {
                            clk=0;
                            SC=0;
                            lineStep++;
                            logicUnitAND();
                            ui->ope_line->setText("AC <- AC^DR  , SC <- 0");
                        }



                    }



                    else if(riz.at(0)=="ADD")
                    {
                        //t3
                        if(clk==3)
                        {
                            clk++;

                            if(riz.size()>=3 && riz.at(2)=='I')
                            {

                                ui->ope_line->setText("AR <- M[AR] ");
                                bitset<12> tmpAR=AR;
                                for (int bitC=0;bitC<12;bitC++)
                                {
                                    AR[bitC]=ram[tmpAR.to_ulong()][bitC];


                                }


                            }
                            else
                            {

                            }

                        }

                        //t4
                        if(clk==4)
                        {
                            clk++;
                            DR=ram[AR.to_ulong()];
                            ui->ope_line->setText("DR <- M[AR]");

                        }

                        //t5
                        if(clk==5)
                        {
                            clk=0;
                            lineStep++;
                            SC=0;
                            arithmeticUnitADD();
                            ui->ope_line->setText(" AC <- AC+DR , E<-COUT , SC <- 0");

                        }




                    }




                    else if(riz.at(0)=="LDA")
                    {
                        //t3
                        if(clk==3)
                        {
                            clk++;
                            if(riz.size()>=3 && riz.at(2)=='I')
                            {
                                ui->ope_line->setText("AR <- M[AR] ");
                                bitset<12> tmpAR=AR;
                                for (int bitC=0;bitC<12;bitC++)
                                {
                                    AR[bitC]=ram[tmpAR.to_ulong()][bitC];

                                }

                            }
                            else
                            {

                            }
                        }

                        //T4
                        else if(clk==4)
                        {
                            clk++;
                            DR=ram[AR.to_ulong()];
                            ui->ope_line->setText("DR <- M[AR]");

                        }


                        //t5
                        else if (clk==5) {
                            SC=0;
                            clk=0;
                            lineStep++;
                            AC=DR;
                            ui->ope_line->setText("AC <- DR , SC <- 0");

                        }



                    }



                    else if(riz.at(0)=="STA")
                    {
                        if(clk==3)
                        {
                            clk++;
                            if(riz.size()>=3 && riz.at(2)=='I')
                            {
                                ui->ope_line->setText("AR <- M[AR] ");
                                bitset<12> tmpAR=AR;
                                for (int bitC=0;bitC<12;bitC++)
                                {
                                    AR[bitC]=ram[tmpAR.to_ulong()][bitC];

                                }

                            }
                            else
                            {

                            }
                        }
                        //t4
                        else if(clk==4)
                        {
                            ui->ope_line->setText("M[AR] <- AC , SC <- 0");
                            SC=0;
                            lineStep++;
                            clk=0;
                            ram[AR.to_ulong()]=AC;
                            QTableWidgetItem *empty = new QTableWidgetItem();
                            empty->setText("");
                            ui->RAM->setItem(firstallDatas[riz.at(1)],2,empty);
                        }

                        //ui->in_line->setText(QString::number(lc));

                    }

                    else if(riz.at(0)=="BUN")
                    {
                        int Ichecker;
                        if(clk==3)
                        {
                            clk++;
                            if(riz.size()>=3 && riz.at(2)=='I')
                            {
                                ui->ope_line->setText("AR <- M[AR] ");
                                bitset<12> tmpAR=AR;
                                for (int bitC=0;bitC<12;bitC++)
                                {
                                    AR[bitC]=ram[tmpAR.to_ulong()][bitC];

                                }

                                //qDebug()<<"go to memory: "<<ram[tmpAR.to_ulong()].to_ulong();
                                //qDebug()<<"go to line: "<<AR.to_ulong();
                                Ichecker=1;
                                //lineStep=memoryToLine[AR.to_ulong()]-1;


                            }
                            else
                            {
                                Ichecker=0;

                            }
                            //qDebug()<<AR.to_ulong();
                            //
                            //ui->in_line->setText(QString::number(lineStep));
                        }

                        //t4
                        else if(clk==4)
                        {
                            ui->ope_line->setText("PC <- AR , SC <- 0");
                            SC=0;
                            clk=0;
                            PC=AR;
                            if(Ichecker)
                            {
                               lineStep=memoryToLine[AR.to_ulong()]-1;
                               //qDebug()<<"gotolineStep: "<<lineStep;
                            }
                            else
                            {
                               lineStep=allDatas[riz.at(1)+","]-1;
                               //qDebug()<<"gotolineStep!!!!!!!!!!!!: "<<lineStep;
                            }


                            lineStep++;
                            //ui->in_line->setText(QString::number(lineStep));
                            memorystep=PC.to_ulong();

                        }

                    }




                    else if(riz.at(0)=="BSA")
                    {
                        if(clk==3)
                        {
                            clk++;
                            if(riz.size()>=3 && riz.at(2)=='I')
                            {
                                ui->ope_line->setText("AR <- M[AR] ");
                                bitset<12> tmpAR=AR;
                                for (int bitC=0;bitC<12;bitC++)
                                {
                                    AR[bitC]=ram[tmpAR.to_ulong()][bitC];

                                }

                            }
                            else
                            {

                            }
                        }
                        //t4
                        else if(clk==4)
                        {
                            ui->ope_line->setText("M[AR] <- PC , AR <- AR+1");
                            clk++;
                            incAR();
                            //qDebug()<<"where to write in memory"<<AR.to_ulong()-1;
                            //qDebug()<<"write in memory: "<<PC.to_ulong();
                            for (int bitC=0;bitC<12;bitC++)
                            {
                                ram[(AR.to_ulong())-1][bitC]=PC[bitC];

                            }
                        }


                        //T5
                        else if(clk==5)
                        {
                            clk=0;
                            PC=AR;
                            lineStep=allDatas[riz.at(1)+","]; //shak
                            lineStep++;
                            //qDebug()<<"line: "<<lineStep;
                            SC=0;

                            memorystep=PC.to_ulong();
                            ui->ope_line->setText("PC <- AR , SC <- 0");

                        }


                    }


                    else if(riz.at(0)=="ISZ")
                    {
                        if(clk==3)
                        {

                            clk++;
                            if(riz.size()>=3 && riz.at(2)=='I')
                            {
                                ui->ope_line->setText("AR <- M[AR] ");
                                bitset<12> tmpAR=AR;
                                for (int bitC=0;bitC<12;bitC++)
                                {
                                    AR[bitC]=ram[tmpAR.to_ulong()][bitC];

                                }

                            }
                            else
                            {

                            }
                        }
                        //t4
                        else if(clk==4)
                        {
                            ui->ope_line->setText("DR <- M[AR]");
                            clk++;
                            DR=ram[AR.to_ulong()];

                        }

                        //t5
                        else if(clk==5)
                        {
                            ui->ope_line->setText("DR <- DR+1");
                            clk++;
                            incDR();
                        }

                        //t6
                        else if(clk==6)
                        {
                            SC=0;
                            clk=0;
                            lineStep++;
                            ram[AR.to_ulong()]=DR;
                            ui->ope_line->setText("M[AR] <- DR, SC <- 0");
                            if(DR.to_ulong()==0)
                            {
                                incPC();
                                lineStep++;   //shak
                                memorystep++;
                                ui->ope_line->setText("PC <- PC+1 , M[AR] <- DR, SC <- 0");
                            }


                        }


                    }



                    else if(riz.at(0)=="INP")
                    {

                        SC=0;
                        clk=0;
                        lineStep++;
                        bool ok=1;
                        INPR=ui->input_lineedit->text().toInt(&ok,16);
                        for (int bitC=0;bitC<8;bitC++)
                        {
                            AC[bitC]=INPR[bitC];

                        }
                        FGI=0;
                        ui->ope_line->setText("AC(0-7) <- INPR , FGI <- 0 , SC <- 0");


                    }

                    else if(riz.at(0)=="OUT")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        for (int bitC=0;bitC<8;bitC++)
                        {
                            OUTR[bitC]=AC[bitC];

                        }
                        FGO=0;
                        ui->ope_line->setText("OUTR <- AC(0-7), FGO <- 0 , SC <- 0");

                    }
                    else if(riz.at(0)=="SKI")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        ui->ope_line->setText("SC <- 0");
                        if(FGI==1)
                        {
                            incPC();
                            lineStep++; //shak
                            memorystep++;
                            ui->ope_line->setText("PC <- PC+1 , SC <- 0");
                        }
                    }
                    else if(riz.at(0)=="SKO")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        ui->ope_line->setText("SC <- 0");
                        if(FGO==1)
                        {
                            incPC();
                            lineStep++; //shak
                            memorystep++;
                            ui->ope_line->setText("PC <- PC+1 , SC <- 0");
                        }
                    }
                    else if(riz.at(0)=="ION")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        IEN=1;
                        ui->ope_line->setText("IEN <- 1 , SC <- 0");
                    }
                    else if(riz.at(0)=="IOF")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        IEN=0;
                        ui->ope_line->setText("IEN <- 0 , SC <- 0");
                    }

                    ////////////////////////////////////////////////////////////////////////////////
                    else if(riz.at(0)=="CLA")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        AC=0;
                        ui->ope_line->setText("AC <- 0  , SC <- 0 ");
                    }

                    else if(riz.at(0)=="CLE")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        E=0;
                        ui->ope_line->setText("E <- 0  , SC <- 0 ");
                    }
                    else if(riz.at(0)=="CMA")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        AC.flip();
                        ui->ope_line->setText("AC <- ~AC  , SC <- 0 ");
                    }
                    else if(riz.at(0)=="CME")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        E.flip();
                        ui->ope_line->setText("E <- ~E  , SC <- 0 ");
                    }
                    else if(riz.at(0)=="CIR")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                       arithmeticUnitCIR();
                       ui->ope_line->setText("AC <- shr  , AC(15)<-E , E <- AC(0) ");

                    }
                    else if(riz.at(0)=="CIL")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        arithmeticUnitCIL();
                        ui->ope_line->setText("AC <- shl  , AC(0)<-E , E <- AC(15) ");

                    }
                    else if(riz.at(0)=="INC")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        incAC();
                        ui->ope_line->setText("AC <- AC+1  , SC <- 0 ");
                    }
                    else if(riz.at(0)=="SPA")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        ui->ope_line->setText("SC <- 0 ");
                        if(AC[15]==0)
                        {
                            ui->ope_line->setText("PC <- PC+1  , SC <- 0 ");
                            incPC();
                            lineStep++; //shak
                            memorystep++;
                        }
                    }
                    else if(riz.at(0)=="SNA")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        ui->ope_line->setText("SC <- 0 ");
                        if(AC[15]==1)
                        {
                            incPC();
                            lineStep++; //shak
                            memorystep++;
                            ui->ope_line->setText("PC <- PC+1  , SC <- 0 ");
                        }
                    }
                    else if(riz.at(0)=="SZA")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        ui->ope_line->setText("SC <- 0 ");
                        if(AC.to_ulong()==0)
                        {
                            incPC();
                            lineStep++; //shak
                            memorystep++;
                            ui->ope_line->setText("PC <- PC+1  , SC <- 0 ");
                        }
                    }
                    else if(riz.at(0)=="SZE")
                    {
                        SC=0;
                        clk=0;
                        lineStep++;
                        ui->ope_line->setText("SC <- 0 ");
                        if(E.to_ulong()==0)
                        {
                            incPC();
                            lineStep++; //shak
                            memorystep++;
                            ui->ope_line->setText("PC <- PC+1  , SC <- 0 ");
                        }
                    }
                    else if(riz.at(0)=="HLT")
                    {
                        S=0;
                        SC=0;
                        clk=0;
                        lineStep++;
                        ui->run_pbtn->setEnabled(false);
                        ui->next_pbtn->setEnabled(false);
                        ui->ope_line->setText("S <- 0");

                        ui->console_txt->setText("program run successfully! \n");
                        if(printing)
                        {
                            printReg();
                            printTable();
                        }
                        return;
                    }

                    else if(riz.at(0)=="END")
                    {
                        clk=0;
                        lineStep++;
                        if(printing)
                        {
                            printReg();
                            printTable();
                        }
                        ui->console_txt->setText("program run successfully! \n");
                        ui->run_pbtn->setEnabled(false);
                        ui->next_pbtn->setEnabled(false);
                        return;
                    }
                    else
                    {
                        clk=0;
                        lineStep++;
                        if(printing)
                        {
                            printReg();
                            printTable();
                        }
                        ui->console_txt->setText("Error in running program!\n");
                        ui->run_pbtn->setEnabled(false);
                        ui->next_pbtn->setEnabled(false);
                        return;
                    }


                    if(printing)
                    {
                        printReg();
                        printTable();
                    }

        }
}

void MainWindow::on_run_btn_clicked()
{
    if(!compiled)
    {
        ui->console_txt->setText("\n You should compile your program first!\n");
    }

    else
    {
        S=1;
        printing=0;
        run=1;
        while ((S.to_ulong()))
        {
            on_next_btn_clicked();
        }
        printReg();
        printTable();
    }
}



void MainWindow::on_new_btn_clicked()
{
    on_actionNew_triggered();
    compiled=0;
}


void MainWindow::on_open_btn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Text file"), "",tr("Myeditor file (*.bxb)"));
    if (fileName.isEmpty())
        return;
    else {
        ui->code_txtedit->clear();
        issaved=fileName;
        ifstream infile;
        infile.open(fileName.toLocal8Bit());
        char tmp[300];
        while(infile.eof()!=true)
        {
            //infile>>tmp;
            infile.getline(tmp,300);
            ui->code_txtedit->insertPlainText(QString::fromStdString(tmp));
            ui->code_txtedit->insertPlainText("\n");
            compiled=0;

        }
    }
}

void MainWindow::on_save_btn_clicked()
{
    if(issaved=="")
    {
        on_actionSave_As_triggered();
    }
    else
    {
        ofstream f;
        f.open(issaved.toLocal8Bit(),ios::out);
        f<<ui->code_txtedit->toPlainText().toStdString();
        f.flush();
        f.close();

    }

}

void MainWindow::on_actionNew_triggered()
{
    ui->code_txtedit->clear();
    issaved="";
    compiled=0;
}

//???open button
void MainWindow::on_actionOpen_triggered()
{
    on_open_btn_clicked();
    compiled=0;
}

//???
void MainWindow::on_actionSave_triggered()
{
    on_save_btn_clicked();
}


void MainWindow::on_actionSave_As_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this,tr("Save"), "",tr("Mytext editor file (*.bxb)"));
    if (fileName.isEmpty())
         return;
     else {


        ofstream f;
        f.open(fileName.toLocal8Bit(),ios::out);
        f<<ui->code_txtedit->toPlainText().toStdString();
        f.flush();
        f.close();

        issaved=fileName;
    }

}

//??
void MainWindow::on_actionCompile_triggered()
{
    on_compile_btn_clicked();
}

//??
void MainWindow::on_actionRun_triggered()
{
    on_run_btn_clicked();
}

