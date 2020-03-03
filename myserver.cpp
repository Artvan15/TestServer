#include "myserver.h"

myserver::myserver(QObject * parent):QTcpServer(parent){
    if(!this->listen(QHostAddress::Any, 5555)){
        qDebug() << "Error";
    }
    else{
        qDebug() << "Listening";
    }
}

void myserver::incomingConnection(qintptr socketDescriptor){
    qDebug() << socketDescriptor << " connecting";
    MyThread *thread = new MyThread(socketDescriptor, this);

    connect(thread, &MyThread::finished, thread, &MyThread::deleteLater);
    thread->start();
}

void myserver::sockReady(){

}

void myserver::sockDisc(){
    qDebug() << "Disconnect";
    socket->deleteLater(); //as soon as possible delete socket

}

void myserver::bytesWritten(qint64 bytes){
    qDebug() << "We wrote " << bytes;
}
