#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QDebug>
#include <QVector>
#include "Check.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void setCheckInform(quint16 LocalPort,bool Route,int Id);
    void deviceClose();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void deleteThread(int Route,quint16 DevicePort);//删除线程

private:
    Check *upCheck[100];
    Check *downCheck[100];
    int upCnt;
    int downCnt;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
