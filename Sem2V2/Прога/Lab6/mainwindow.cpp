#include "mainwindow.h"
Num::Num(QWidget* wgt) : QWidget(wgt = nullptr)
{
    QLabel* Text1 = new QLabel("Делимое: ");
    QLabel* Text2 = new QLabel("Делитель: ");

    edit1 = new QLineEdit;
    edit2 = new QLineEdit;
    QGridLayout* Z = new QGridLayout;
    Z->setContentsMargins(5, 5, 5, 5);
    Z->setSpacing(3);
    Z->addWidget(Text1, 0, 0);
    Z->addWidget(edit1, 1, 0);
    Z->addWidget(Text2, 2, 0);
    Z->addWidget(edit2, 3, 0);
    Z->addWidget(Button(), 6, 0, Qt::AlignCenter);

    setLayout(Z);
}
QPushButton* Num::Button() {
    QPushButton* btn = new QPushButton(" Разделить с остатком ");
    connect(btn, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return btn;
}
void Num::slotButtonClicked() {
    QString str1 = edit1->text();
    QString str2 = edit2->text();

    a = str1.toInt();
    b = str2.toInt();
    bool t1=true, t2=false;
QMessageBox::information(this, "Ответ: ", QString("Неполное частное = %1;\nОстаток = %2").arg(func(t1)).arg(func(t2)));
}
int Num::func(bool t) {
    int i = a + 1, rest = b + 1;
    if (a > 0)
        i = i * (-1) + 2;
    if (b > 0)
        rest = rest * (-1) + 2;
    for (; abs(i) < abs(a); i++) {
        for (int r = rest; abs(r) < abs(b); r++) {
            if (b*i + r == a) {
                if ((a <= 0 && b >= 0) || (b <= 0 && a >= 0)) {
                    i++;
                    r = a - b * i;
                }
                if (t)
                    return i;
                return r;
            }
        }
    }
    return i;
}
