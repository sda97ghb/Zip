#include "mainwindow.h"
#include <QApplication>

#include "aux.h"
#include "zipparser.h"

#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Unzip unzip("/home/dmitry/tests.zip");
//    unzip.execute();

    return a.exec();
}
