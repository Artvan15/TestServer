#include "myserver.h"

myserver::myserver(QObject * parent):QTcpServer(parent){
    if(this->listen(QHostAddress::Any), 5555){
        qDebug() << "Listerning!";
    }
    else{
        qDebug() << "Not listerning!";
    }
}

void myserver::incomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket(this); //create socket
    socket->setSocketDescriptor(socketDescriptor); //unique number

    connect(socket, &QTcpSocket::readyRead, this, &myserver::sockRedy);
    connect(socket, &QTcpSocket::disconnected, this, &myserver::sockDisc);

    socket->write("You are connected!");
    qDebug() << "Client " << socketDescriptor << " is connected";
}

void myserver::sockRedy(){

}

void myserver::sockDisc(){
    qDebug() << "Disconnect";
    socket->deleteLater(); //as soon as possible delete socket
}
