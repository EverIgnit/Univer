#include "trans.h"
int NOD(int a, int b)
{
    if (!a||!b)
        return 1;
    int i = a;
    if (b<a)
        i=b;
    for (; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
               return i;
            }
        }
     return i;
}

Trans::Trans(QWidget *parent): QWidget(parent)
{
    cmb = new QComboBox;
    cmb->addItem("+");
    cmb->addItem("-");
    cmb->addItem("*");
    cmb->addItem("/");

    lcdn = new QLCDNumber;
    lcdn->setFixedSize(200,40);
    lcdn->setSegmentStyle(QLCDNumber::Flat);
    lcdn->setDigitCount(15);

    lcdn2 = new QLCDNumber;
    lcdn2->setFixedSize(200,40);
    lcdn2->setSegmentStyle(QLCDNumber::Flat);
    lcdn2->setDigitCount(15);

    line1 = new QLineEdit;
    line2 = new QLineEdit;
    line3 = new QLineEdit;
    line4 = new QLineEdit;

    QPushButton* button = createButton();
    QGridLayout* layout = new QGridLayout;

    layout->setContentsMargins(5,5,5,5);
    layout->setSpacing(8);
    layout->addWidget(line1,0,0);
    layout->addWidget(line2,1,0);
    layout->addWidget(line3,0,1);
    layout->addWidget(line4,1,1);
    layout->addWidget(cmb,0,2);
    layout->addWidget(button,1, 2);
    layout->addWidget(lcdn,0,3);
    layout->addWidget(lcdn2,1,3);

    connect(line1,SIGNAL(textChanged(const QString&)),lcdn,SLOT(display(const QString&)));
    connect(line2,SIGNAL(textChanged(const QString&)),lcdn,SLOT(display(const QString&)));
    connect(line3,SIGNAL(textChanged(const QString&)),lcdn,SLOT(display(const QString&)));
    connect(line4,SIGNAL(textChanged(const QString&)),lcdn,SLOT(display(const QString&)));

    setLayout(layout);
}

QPushButton* Trans::createButton(){
    QPushButton* button = new QPushButton("Вычислить");
    connect(button,SIGNAL(clicked()),SLOT(slotButtonClicked()));
    return button;
}

Trans::~Trans()
{

}

void Trans::slotButtonClicked(){
    QString str1 = line1->text();
    QString str2 = line2->text();
    QString str3 = line3->text();
    QString str4 = line4->text();
    int x1=str1.toInt();
    int y1=str2.toInt();
    int x2=str3.toInt();
    int y2=str4.toInt();
    int result1=0, result2=0;

    if (y1==0||y2==0){
        lcdn->display("ERROR");
        lcdn->display("ERROR");
    }
    else{
        if(cmb->currentText()=="+"){
            result1=(x1*y2+x2*y1)/NOD(abs(x1*y2+x2*y1),abs(y1*y2));
            result2=((y1*y2)/NOD(abs(x1*y2+x2*y1),abs(y1*y2)));
        }
        else
        if(cmb->currentText()=="-"){
            result1=(x1*y2-x2*y1)/NOD(abs(x1*y2-x2*y1),abs(y1*y2));
            result2=(y1*y2)/NOD(abs(x1*y2-x2*y1),abs(y1*y2));
        }
        else{
            if(cmb->currentText()=="*"){
                if (x1==0||x2==0){
                    result1=0;
                    result2=y1*y2;
                }
                else{
                    result1=(x1*x2)/NOD(abs(x1*x2),abs(y1*y2));
                    result2=(y1*y2)/NOD(abs(x1*x2),abs(y1*y2));
                }
            }
            else{
                if (x2==0){
                    lcdn->display("ERROR");
                    lcdn->display("ERROR");
                }
                else{
                    if(cmb->currentText()=="/"){
                        if (x1==0||x2==0){
                            result1=0;
                            result2=y1*x2;
                        }
                        else{
                            result1=(x1*y2)/NOD(abs(x1*y2),abs(y1*x2));
                            result2=(y1*x2)/NOD(abs(x1*y2),abs(y1*x2));
                        }
                    }
                }
            }
        }
        if (x2){
            if (result1<0&&result2<0){
            result1*=-1;
            result2*=-1;
        }
            lcdn->display(result1);
            lcdn2->display(result2);
            lcdn->display(result1);
            lcdn2->display(result2);
        }
    }
}
