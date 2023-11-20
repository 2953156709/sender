#include "Check.h"


Check::Check()
{
    //生成检测数据间隔（单位ms）
    interval = 1000;
    //组播ip
    groupAddress = QHostAddress("239.0.0.1");
    //定时器（生成检测数据)
    dataTime = new QTimer();
    dataTime->setInterval(interval);
    connect(dataTime,&QTimer::timeout,this,&Check::makeData);
    dataTime->start();
}

Check::~Check()
{
    delete dataTime;
    delete socket;
}

void Check::run()
{

    //设置组播接收与单播发送
    socket = new QUdpSocket();
    socket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
    socket->bind(QHostAddress::AnyIPv4,localPort,QUdpSocket::ShareAddress);
    socket->joinMulticastGroup(groupAddress);
    socket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,1024*1024);//设置接收缓存区大小
    connect(socket,&QUdpSocket::readyRead,this,&Check::setData,Qt::DirectConnection);
    connect(this,&Check::dataComplete,this,&Check::receiveCmd,Qt::DirectConnection);
    exec();//开启子线程事件循环

}
//接受激活命令
void Check::receiveCmd()
{
    //读取信息
    activateCmd.resize(socket->pendingDatagramSize());
    socket->readDatagram(activateCmd.data(),activateCmd.size(),&clientAddress,&clientPort);
    if(activateCmd=="activate"&&sendable)//如果信息为激活命令且可以发送数据
    {
        //发送检测数据
        sendDataByte = sendData.toUtf8();
        socket->writeDatagram(sendDataByte,clientAddress,clientPort);
        sendData.clear();
    }
}

//生成检测数据
void Check::makeData()
{
    if(hour==23)
    {
        hour = 0;
        day++;
    }
    else
        hour++;
    if(temp.size()==24)
    {
        temp.dequeue();
        high.dequeue();
        temp.enqueue(tempSource[hour]);
        high.enqueue(highSource[hour]);
    }
    else
    {
        temp.enqueue(tempSource[hour]);
        high.enqueue(highSource[hour]);
    }
}
//检测设备状态
void Check::checkStatus()
{
    sendData += "C=";
}
//设置发送的数据
void Check::setData()
{
    sendData += '#';
    checkStatus();
    sendData += QString::number(route);
    sendData += '=';
    sendData += QString::number(ID);
    sendData += '=';
    sendData += QString::number(day);
    QQueue<double> Temp = temp;
    QQueue<double> High = high;
    while(!Temp.isEmpty())
    {
        sendData += '=';
        sendData += QString::number(Temp.dequeue());
        sendData += '=';
        sendData += QString::number(High.dequeue());
    }
    sendData += '\0';
    emit dataComplete();
}

void Check::exitThread()
{
    disconnect(socket,&QUdpSocket::readyRead,this,&Check::setData);
    emit stopOver(route,localPort);
}
//设置设备信息
void Check::receiveInform(quint16 LocalPort,int Route,int Id)
{
    if(informSetable)
    {
        localPort =LocalPort;
        route = Route;
        ID = Id;
        informSetable = false;
    }

}
