#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    upCnt = ui->spinBox->value();
    for(int i=0;i<upCnt;i++)
    {
        upCheck[i] = new Check;
        connect(this,&MainWindow::setCheckInform,upCheck[i],&Check::receiveInform);
        connect(this,&MainWindow::deviceClose,upCheck[i],&Check::exitThread);
        emit setCheckInform(1101+i,0,1001+i);
        upCheck[i]->start();
    }
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
}


void MainWindow::on_pushButton_2_clicked()
{
    downCnt = ui->spinBox_2->value();
    for(int i=0;i<downCnt;i++)
    {
        downCheck[i] = new Check;
        connect(this,&MainWindow::setCheckInform,downCheck[i],&Check::receiveInform);
        connect(this,&MainWindow::deviceClose,downCheck[i],&Check::exitThread);
        emit setCheckInform(1201+i,1,1001+i);
        downCheck[i]->start();
    }
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
}


void MainWindow::on_pushButton_3_clicked()
{
    emit deviceClose();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::deleteThread(int Route,quint16 DevicePort)
{
    if(Route==0)
    {
        Check *check = upCheck[DevicePort-1101];
        check->deleteLater();
    }
    else
    {
        Check *check = downCheck[DevicePort-1201];
        check->deleteLater();
    }
}

