#pragma once
#include <QMainWindow>
#include <QtWidgets>
#include <QPainter>
#include <QVector>
#include <QPair>
#include <QDialog>


namespace Ui {
class MainWindow;
}

/*
class DialogPen: public QDialog
{
    Q_OBJECT
public:
    DialogPen(QWidget* parent = nullptr);

private:
    QComboBox* penStyle;
    QPushButton* setStyle;
    QString state;
public slots:
    void slotStyleState();
    friend class MainWindow;
};


*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*);


public slots:
   void openDlg();
   void openBruh();
   void clrArr();
   void fileOpen();


private:
    Ui::MainWindow *ui;

    int arr_size=0;
    long sub_size=0;
    QPointF position;

    QPen curPen;
    QBrush bruh;
    QVector<QPointF> coords = {{0,77},{0,77}};
    QRectF tmpRect;//for rects and ellipses
    QColorDialog* colorDlg;
    QColorDialog* brushDlg;

    QComboBox* penStyle;
    QComboBox* brushStyle;
    QSpinBox* penSize;

    QPixmap pix;
    QLinearGradient linGrad;
    QStringList fileName;
    QPointF crds[1000];

protected:
    void dump(QMouseEvent*);
    virtual void mouseMoveEvent (QMouseEvent* ev);
    virtual void mousePressEvent(QMouseEvent* ev);
    //void load(QString);

};

