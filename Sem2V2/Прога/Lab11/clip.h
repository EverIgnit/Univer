#pragma once
#include <QWidget>
#include <QtWidgets>

namespace Ui {
class Clip;
}

class Clip : public QWidget
{
    Q_OBJECT

public:
    explicit Clip(QWidget *parent = nullptr);
    ~Clip();

private:
    Ui::Clip *ui;


public slots:
    void slotDataControl();
    void textClip();
    void imageClip();
};

