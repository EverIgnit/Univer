#pragma once

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class MDIDoc;
}

class MDIDoc : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDIDoc(QMainWindow* parent = nullptr);
    ~MDIDoc() override;

private:
    Ui::MDIDoc* ui;
    QString fileName;
    QFontDialog* fontDlg;
    void setCurrentFileName(const QString &fileName);
    bool maybeSave();
   // bool load(const QString& f);

protected:
    void closeEvent(QCloseEvent *e) override;

signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad  ();
    void slotFonts ();
    bool slotSave  ();
    bool slotSaveAs();
    void slotStatusText();//
    void slotStatusDir();
friend class MDI8;
};

