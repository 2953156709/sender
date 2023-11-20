#ifndef UPCHECK0X01_H
#define UPCHECK0X01_H

#include <QThread>
#include <QUdpSocket>
#include <QDebug>
#include <QQueue>
#include <QTimer>
#include <QDataStream>
#include <cstdlib>
#include <ctime>

class Check : public QThread
{
    Q_OBJECT
public:
    Check();
    ~Check();
    void run();
signals:
    void dataComplete();//发送数据生成完毕
    void stopOver(int Route,quint16 LocalPort);//停止完成信号

public slots:
    void receiveInform(quint16 LocalPort,int Route,int Id);//设置设备信息
    void receiveCmd();//接受激活信息
    void makeData();//生成检测数据
    void checkStatus();//检测设备状态
    void setData(); //设置发送数据
    void exitThread();//关闭线程
private:

    QUdpSocket *socket;
    quint16 localPort;
    quint16 clientPort;
    QHostAddress groupAddress;
    QHostAddress clientAddress;
    QByteArray activateCmd;
    QTimer *dataTime;
    QQueue<double> temp;
    QQueue<double> high;
    int ID;
    int hour = rand()%24;
    int day = 0;
    int interval;
    int route;
    QByteArray sendDataByte;
    bool sendable = true;
    bool informSetable = true;
    QString sendData = "";
    double tempSource[24] = {-7.5,-6.7,-4.4,-0.8,3.9,9.4,15.3,21.2,26.7,31.4,35.1,37.3,38.1,37.3,35.1,31.4,26.7,21.2,15.3,9.4,3.9,-0.8,-4.4,-6.7};
    double highSource[24] = {3.25,3.24,3.49,3.85,4.44,4.89,5.22,5.9,6.35,6.73,7.1,6.81,6.35,5.76,5.32,4.84,4.29,3.89,3.55,3.29,3.16,3.64,3.98,3.49};
};


#endif // CHECK_H
