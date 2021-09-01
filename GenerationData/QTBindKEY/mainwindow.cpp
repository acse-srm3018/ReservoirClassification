#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "keyboard.h"
#include <QStringList>
#include <QString>

#define elseif else if
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Pansys sender");
    timer = new QTimer(this);
    clipboard = QApplication::clipboard();
    file = new QFile(this);
    setFixedSize(size());
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(startButton()));
    connect(ui->action_Close,SIGNAL(triggered()),this,SLOT(close()));
    connect(timer,SIGNAL(timeout()),this,SLOT(nextKeyEvent()));
    connect(ui->browsbutton,SIGNAL(clicked()),SLOT(getFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete file;
    delete timer;
}

void MainWindow::startButton()
{
    if(!file->isOpen())
    {
        file->setFileName(path);
        file->open(QIODevice::ReadOnly);
    }
    if(file->isOpen())
    {
        timer->start(ui->time->value());
        mult=ui->stime->value();
        showMinimized();
    }
}

void MainWindow::getFile()
{
    path=QFileDialog::getOpenFileName(this,"Brows File",QDir::currentPath(),tr("text file (*.txt)"));
    if(!path.isEmpty())
    {
        file->setFileName(path);
        QFileInfo fi(path);
        ui->filename->setText(fi.fileName());
    }
}


void MainWindow::nextKeyPress()
{

}

void virtualTypeText(const QString &text)
{
    SHORT WINAPI ch;
    for(auto c:text)

    {
        ch = VkKeyScan(c.toUpper().toLatin1());
//        shift = (ch & 0x100) > 0;
//        ctrl = (ch & 0x200) > 0;
//        alt = (ch & 0x400) > 0;
        if ((ch & 0x100) > 0){
            SHIFT_Key(doKey(ch));

        }
        else {
            doKey(ch);
        }
    }
}

void MainWindow::nextKeyEvent()
{
    static int level=-1,state=1;
    static QStringList t;
    if(level==0)
    {

        QString tt=file->readLine();
        tt.replace(" ","");
        t=tt.split(QRegExp("\\s+"),QString::SkipEmptyParts);
        if(tt.isEmpty()||t.count()<6){
            timer->stop();
            showMaximized();
            QMessageBox::warning(this,"finished progrss"
                                 ,t.count()<6?
                                 ("The column count is less than 6 .\nCheck your file !"):
                                 QString("The %1 linesam was read .").arg(state)
                                 ,QMessageBox::Ok,QMessageBox::Ok);
            state=1;
            level=-1;
            return;
        }

    }
    elseif(level==1)
    {
        ALT
        D
        W
    }
    elseif(level==2)
    {
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        ENTER
    }
    elseif(level==3)
    {
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        TAB
        ENTER
    }
    elseif(level==4)
    {
        virtualTypeText(t[0]);
        TAB
    }
    elseif(level==5)
    {
        virtualTypeText(t[1]);
        TAB
    }
    elseif(level==6)
    {
        virtualTypeText(t[2]);
        TAB
        TAB
    }
    elseif(level==7)
    {
        virtualTypeText(t[3]);
        TAB
    }
    elseif(level==8)
    {
        virtualTypeText(t[4]);
        TAB
    }
    elseif(level==9)
    {
        virtualTypeText(t[5]);
        ENTER
    }
    elseif(level==10)
    {
        TAB
        ENTER
    }
    elseif(level==11)
    {
        TAB
        TAB
        TAB
        ENTER
    }
    elseif(level==12)
    {
        ALT
        S
        D
    }
    elseif(level==13)
    {
        ENTER
    }
    elseif(level==14)
    {
        ENTER
    }
    elseif(level==15)
    {
        ENTER
    }
    elseif(level==16)
    {
        ENTER
    }
    elseif(level==17)
    {
        ENTER
    }
//    elseif(level==13+mult)
//    {
//        ENTER
//    }
//    elseif(level==15+2*mult)
//    {
//        ENTER
//    }
    elseif(level==17+mult)
    {
        ENTER
    }
    elseif(level==18+mult)
    {
        ALT
        D
        G
    }
    elseif(level==19+mult)
    {
        ALT_Key(X)
    }
    elseif(level==20+mult)
    {
        TAB
        S
    }
    elseif(level==21+mult)
    {
        TAB
        N
    }
    elseif(level==22+mult)
    {
        TAB
        N
    }
    elseif(level==23+3*mult)
    {
        TAB
        N
    }
    elseif(level==24+mult)
    {
        TAB
        N
    }
    elseif(level==25+mult)
    {
        TAB
        N
    }
    elseif(level==26+mult)
    {
        TAB
        N
    }
    elseif(level==27+mult)
    {
        TAB
        TAB
        TAB
        TAB
        TAB
    }
    elseif(level==28+mult)
    {
        DOWN_Arrow
        DOWN_Arrow
    }
    elseif(level==29+mult)
    {
        ENTER
    }
    elseif(level==30+mult)
    {
        virtualTypeText(tr("%1%2%3%4%5").arg(state/10000%10).arg(state/1000%10).arg(state/100%10).arg(state/10%10).arg(state%10));
    }
    elseif(level==31+mult)
    {
        ENTER
    }
    elseif(level==32+mult)
    {
//        ESCAPE
        ALT_Key(F4)
    }
    elseif(level==33+mult)
    {
        state++;
        level=-1;

    }

    level++;
}

void MainWindow::showEvent(QShowEvent *e)
{
    timer->stop();
}
