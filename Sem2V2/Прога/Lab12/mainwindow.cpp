#include "mainwindow.h"
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
Tower * newTower(QWidget *centralWidget)
{
 QFrame *frame = new QFrame(centralWidget);
 frame->setFrameShape(QFrame::StyledPanel);
 frame->setFrameShadow(QFrame::Raised);
 Tower *tower = new Tower(frame);
 QVBoxLayout *layout = new QVBoxLayout(frame);
 layout->addWidget(tower);
 centralWidget->layout()->addWidget(frame);
 return tower;
}
MainWindow::MainWindow(QWidget *parent) :
 QMainWindow(parent)
{
 resize(400, 300);
 centralWidget = new QWidget(this);
 horizontalLayout = new
QHBoxLayout(centralWidget);
 tower_1 = newTower(centralWidget);
 tower_2 = newTower(centralWidget);
 tower_3 = newTower(centralWidget);
 setCentralWidget(centralWidget);
 for (int size = 3; size > 0; --size)
tower_1->addDisk(size);
}
