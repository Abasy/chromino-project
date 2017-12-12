#include "mainwindowchromino.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowChromino w;
    w.show();

    return a.exec();
}
