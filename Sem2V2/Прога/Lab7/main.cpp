#include "trans.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Trans w;
    w.show();
    return a.exec();
}
