#include "mythread.h"

MyThread::MyThread(qintptr ID, QObject *parent):QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run(){
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }

    connect(socket, &QTcpSocket::readyRead, this, &MyThread::readyRead, Qt::DirectConnection);
    connect(socket, &QTcpSocket::disconnected, this, &MyThread::disconnected, Qt::DirectConnection);

    exec();
}

void MyThread::readyRead(){
    QByteArray Data = socket->readAll();
    qDebug() << socketDescriptor << " Data in " << Data;
    socket->write(Data);
}

void MyThread::disconnected(){
    qDebug() << "Disconnected " << socketDescriptor;
    socket->deleteLater();
    exit(0);

}
