#include <QCoreApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::unique_ptr<myserver> Server(std::make_unique<myserver>());

    return a.exec();
}
