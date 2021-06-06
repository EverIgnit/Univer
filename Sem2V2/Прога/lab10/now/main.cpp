#include "mdi8.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MDI8 w;
    w.show();

    return a.exec();
}
