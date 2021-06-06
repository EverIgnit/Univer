#include <QWidget>
#include <QtWidgets>
class QPushButton;
class Num : public QWidget {
    Q_OBJECT
private:
    QLineEdit* edit1;
    QLineEdit* edit2;
    int a, b;
public:
    Num (QWidget* wgt = nullptr);
    QPushButton* Button();
    int func(bool);
public slots:
    void slotButtonClicked();
};
