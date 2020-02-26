#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <memory>

class myserver : public QTcpServer
{
    Q_OBJECT
public:
    myserver(QObject *parent = 0);

    QTcpSocket *socket;
    QByteArrayData Data;

public slots:
    void sockRedy();
    void sockDisc();
protected slots:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE; //unique code of connection
};

#endif // MYSERVER_H
