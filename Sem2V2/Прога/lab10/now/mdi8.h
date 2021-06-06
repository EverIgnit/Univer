#pragma once
#include "mdidoc.h"
#include <QWidget>
#include <QtWidgets>

namespace Ui {
class MDI8;
}

class MDI8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDI8(QMainWindow *parent = nullptr);
    ~MDI8();
    bool load(const QString& f);

private:
    Ui::MDI8 *ui;
    MDIDoc* newDoc();
    QSignalMapper* sigMap;

public slots:
    void slotNewDoc();
    void slotLoad();
    void slotAbout();
    void slotWindows();
    void slotSetActiveSubWindow(QWidget*);
    void slotChangeWindowTitle(const QString&);

friend class MDIDoc;
};

