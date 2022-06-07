#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<bitset>
#include<map>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //quint16 : Typedef for unsigned short. This type is guaranteed to be 16-bit on all platforms supported by Qt.
    quint16 getE();
    quint16 getDR();
    quint16 getAC();
    bool getACleadingBit();
    quint16 getIR();
    quint16 getTR();
    quint16 getAR();
    quint16 getPC();
    quint16 getINPR();
    quint16 getOUTR();


    void setE(const quint16& E);
    void setDR(const quint16& DR);
    void setAC(const quint16& AC);
    void setIR(const quint16& IR);
    void setTR(const quint16& TR);
    void setAR(const quint16& AR);
    void setPC(const quint16& PC);
    void setINPR(const quint8& INPR);
    void setOUTR(const quint8& OUTR);


    void incAR();
    void incPC();
    void incDR();
    void incAC();
    void incTR();

    void clrAR();
    void clrPC();
    void clrDR();
    void clrAC();
    void clrTR();

    void logicUnitAND();
    void logicUnitCMA();
    void logicUnitCME() { E = ~E; }
    void arithmeticUnitADD();
    void arithmeticUnitCIR();
    void arithmeticUnitCIL();

    void emptyTable();
    void resetRam();
    void printReg();
    void printTable();

    bool isNumber(const QString& str);


private slots: 
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered(); 
    void on_actionSave_As_triggered();
    void on_actionCompile_triggered();
    void on_actionRun_triggered();


    void on_compile_pbtn_clicked();

    void on_next_pbtn_clicked();

    void on_reset_pbtn_clicked();

    void on_run_pbtn_clicked();

private:

    Ui::MainWindow *ui;


    QString issaved="";
    bitset<16> ram[4096];
    bitset<16> DR;
    bitset<16> SC;
    bitset<16> AC;
    bitset<16> IR;
    bitset<16> TR;
    bitset<12> AR;
    bitset<12> PC;
    bitset<8> INPR;
    bitset<8> OUTR;
    bitset<1> E;
    bitset<1> I;
    bitset<1> S;
    bitset<1> R;
    bitset<1> IEN;
    bitset<1> FGI;
    bitset<1> FGO;
    map<QString,int> allDatas;
    map<QString,int> firstallDatas;
    QStringList commands;
    int tcommmands;
    int clk;
    int lineStep;
    int memorystep;


    int reseter=1;
    int compiled=0;
    int printing;
    int run;
    map<int,int> memoryToLine;




};
#endif // MAINWINDOW_H
