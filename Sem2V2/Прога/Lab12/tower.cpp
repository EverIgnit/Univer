#include "tower.h"
#include <QWidget>
#include <QLabel>
#include <QMimeData>
#include <QPixmap>
#include <QDrag>
Tower::Tower(QWidget *parent) :
 QWidget(parent)
{
 resize(400,300);
 setAcceptDrops(true);
 verticalLayout = new QVBoxLayout(this);
 verticalSpacer = new QSpacerItem(20, 289,
 QSizePolicy::Minimum,
QSizePolicy::Expanding);
 verticalLayout->addItem(verticalSpacer);
}
bool Tower::addDisk(int size)
{
 if (!canPut(size))
 return false;
 QString name = QString::number(size);
 QLabel *disk = new QLabel(name, this);
 disk->setAlignment(Qt::AlignCenter);
 verticalLayout->insertWidget(1, disk);
 diskSizes.push(size);
 return true;
}
void Tower::mousePressEvent(QMouseEvent *)
{
 if (diskSizes.empty())
 return;
 QWidget *item = verticalLayout->itemAt(1)->widget();
 QLabel *disk = static_cast<QLabel *>(item);
 QMimeData *diskData = new QMimeData;
 diskData->setText(disk->text());
 int diskWidth = disk->width();
 int diskHeight = disk->height();
 QPixmap diskPixmap(diskWidth, diskHeight);
 disk->render(&diskPixmap);
 QDrag *drag = new QDrag(this);
 drag->setMimeData(diskData);
 drag->setPixmap(diskPixmap);
 drag->setHotSpot(QPoint(diskWidth/2,
diskHeight/2));
 if (drag->exec() == Qt::MoveAction) {
 verticalLayout->removeWidget(disk);
 diskSizes.pop();
 delete disk;
 }
}
void Tower::dragEnterEvent(QDragEnterEvent *event)
{
 if (isAcceptable(event))
 event->acceptProposedAction();
}
void Tower::dropEvent(QDropEvent *event)
{
 bool ok;
 int diskSize = eventData(event, &ok);
 if (ok && addDisk(diskSize))
 event->acceptProposedAction();
}
bool Tower::canPut(int size)
{
 return diskSizes.empty() || diskSizes.top() >
size;
}
bool Tower::isAcceptable(const QDropEvent *event)
{
 bool ok;
 int size = eventData(event, &ok);
 if (!ok)
 return false;
 return canPut(size);
}
int Tower::eventData(const QDropEvent *event, bool*ok)
{
 *ok = false;
 QObject *source = event->source();
 if (source == 0 || source == this)
 return 0;
 const QMimeData *mimeData = event->mimeData();
 if (!mimeData->hasText())
 return 0;
 return mimeData->text().toInt(ok);
}
