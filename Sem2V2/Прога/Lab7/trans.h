#pragma once
#include <QWidget>
#include <QtWidgets>


class Trans : public QWidget
{
    Q_OBJECT
    long a;
public:
    Trans(QWidget *parent = 0);
    QPushButton* createButton();
    QLineEdit* line1;
    QLineEdit* line2;
    QLineEdit* line3;
    QLineEdit* line4;
    QComboBox* cmb;
    QLCDNumber* lcdn;
    QLCDNumber* lcdn2;
    ~Trans();
public slots:
    void slotButtonClicked();
};

