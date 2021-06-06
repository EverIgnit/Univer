#include "clip.h"
#include "ui_clip.h"

Clip::Clip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clip)
{
    ui->setupUi(this);
    connect(qApp->clipboard(), SIGNAL(dataChanged()), SLOT(slotDataControl()));
    connect(ui->btnText, SIGNAL(clicked()),SLOT(textClip()));

    connect(ui->btnImage, SIGNAL(clicked()),SLOT(imageClip()));
    QClipboard* pcb = QApplication::clipboard();

    if(!pcb->text().startsWith("file:///") && !pcb->text().isNull())
           ui->clipView->setText(pcb->text());
    else {
        QString str(pcb->text());
        str.remove(0,8);
        QPixmap pix = QPixmap(str);
        ui->clipView->setPixmap(pix);
    }
}

void Clip::slotDataControl()
{
    QClipboard* pcb = QApplication::clipboard();

    if (!pcb->text().startsWith("file:///") && !pcb->text().startsWith("D:/"))
        ui->clipView->setText(pcb->text());
    else {
        QString str(pcb->text());
        if (pcb->text().startsWith("file:///")) {
        str.remove(0,8);
        QPixmap pix = QPixmap(str);
        ui->clipView->setPixmap(pix);
        }
        else {
        QPixmap pix = QPixmap(str);
        ui->clipView->setPixmap(pix);
        }
    }
}

void Clip::textClip()
{
    QClipboard* pcb = QApplication::clipboard();
    pcb->setText(ui->textInput->text());
}

void Clip::imageClip()
{
    QFileDialog dlg(this, "Open Image");
    QStringList mimeType("image");
    dlg.setMimeTypeFilters(mimeType);
    dlg.setFileMode(QFileDialog::ExistingFile);
    if (dlg.exec() != QDialog::Accepted)
        return;
    const QString fn = dlg.selectedFiles().first();
    QFile file(fn);
    QPixmap px = QPixmap(file.fileName());
    QClipboard* cb = QApplication::clipboard();
    cb->setPixmap(px);
    ui->clipView->setPixmap(px);
}

Clip::~Clip()
{
    delete ui;
}
