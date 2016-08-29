#include "mainwindow.h"
#include "boxmonitor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //BoxMonitor bm(999, 13);
    //bm.show();
    w.show();

    return a.exec();
}
