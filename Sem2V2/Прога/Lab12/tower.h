#ifndef TOWER_H
#define TOWER_H
#include <QDragEnterEvent>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QStack>
#include <QWidget>
/* Класс Tower отвечает за отображение одной из башен
 и дисков на ней. Кроме того, этот класс отвечает
за
 возможность перетаскивания дисков */
class Tower : public QWidget
{
Q_OBJECT
public:
 explicit Tower(QWidget *parent = 0);
/* Помещает, если допустимо, диск указанного размера
 на вершину башни*/
 bool addDisk(int size);
protected:
/* Обработка события нажатия кнопки мыши.
 Определяет начало перетаскивания */
 void mousePressEvent(QMouseEvent *);
 /* Обработка события внесения перетаскиваемого
 объекта в виджет */
void dragEnterEvent(QDragEnterEvent *event);
 /* Обработка события бросания в виджет */
 void dropEvent(QDropEvent *event);
private:
 QVBoxLayout *verticalLayout;
 QSpacerItem *verticalSpacer;
 QStack<int> diskSizes;
 bool canPut(int size);
 bool isAcceptable(const QDropEvent *event);
 int eventData(const QDropEvent *event, bool *ok);
};
#endif // TOWER_H
