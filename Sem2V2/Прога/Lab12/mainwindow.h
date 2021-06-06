#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include "tower.h"
class MainWindow : public QMainWindow
{
 Q_OBJECT
public:
 explicit MainWindow(QWidget *parent = 0);
private:
 QWidget *centralWidget;
 QHBoxLayout *horizontalLayout;
 Tower *tower_1;
 Tower *tower_2;
 Tower *tower_3;
};
#endif // MAINWINDOW_H
