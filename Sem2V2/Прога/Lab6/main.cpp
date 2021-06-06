#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Num obj;
    obj.setGeometry(100,50,200,200);
    obj.show();

    return a.exec();
}
