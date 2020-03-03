#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <memory>
#include <QNetworkInterface>
#include "mythread.h"

class myserver : public QTcpServer
{
    Q_OBJECT
public:
    myserver(QObject *parent = 0);

private slots:
    void sockReady();
    void sockDisc();
    void bytesWritten(qint64 bytes);

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE; //unique code of connection

private:
    QTcpSocket *socket;
    QByteArrayData Data;
};

#endif // MYSERVER_H
