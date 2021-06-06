#include "mdi8.h"
#include "ui_mdiArea.h"

MDI8::MDI8(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MDI8)
{
    ui->setupUi(this);

    connect(ui->action_Open,SIGNAL(triggered()),SLOT(slotLoad()));
    connect(ui->action_New,SIGNAL(triggered()),SLOT(slotNewDoc()));

    connect(ui->actionAbout,SIGNAL(triggered()),SLOT(slotAbout()));

    sigMap = new QSignalMapper(this);
    connect(sigMap,
            SIGNAL(mapped(QWidget*)),
            this,
            SLOT(slotSetActiveSubWindow(QWidget*))
           );

    connect(ui->menu_Windows, SIGNAL(aboutToShow()), SLOT(slotWindows()));

}

void MDI8::slotNewDoc()
{
    newDoc()->show();
}

// ----------------------------------------------------------------------
MDIDoc* MDI8::newDoc()
{
    MDIDoc* pdoc = new MDIDoc;

    ui->mdiArea->addSubWindow(pdoc);
    pdoc->setAttribute(Qt::WA_DeleteOnClose);
    pdoc->setWindowTitle("Unnamed Document");
    pdoc->setWindowIcon(QPixmap(":/filenew.png"));
    connect(pdoc,
            SIGNAL(changeWindowTitle(const QString&)),
            SLOT(slotChangeWindowTitle(const QString&))
           );
    statusBar()->showMessage("File Created",2500);
    return pdoc;
}

// ----------------------------------------------------------------------
void MDI8::slotChangeWindowTitle(const QString& str)
{
    qobject_cast<MDIDoc*>(sender())->setWindowTitle(str);
}

// ----------------------------------------------------------------------


void MDI8::slotLoad()
{
    MDIDoc* pdoc = newDoc();
    pdoc->slotLoad();
    pdoc->show();
    statusBar()->showMessage("File Opened",2500);
}



void MDI8::slotAbout()
{
    QMessageBox::about(this, "Application", "MDI Example");
}

void MDI8::slotWindows()
{
    ui->menu_Windows->clear();

    QAction* pact = ui->menu_Windows->addAction("&Cascade",
                                             ui->mdiArea,
                                             SLOT(cascadeSubWindows())
                                            );
    pact->setEnabled(!ui->mdiArea->subWindowList().isEmpty());

    pact = ui->menu_Windows->addAction("&Tile",
                                    ui->mdiArea,
                                    SLOT(tileSubWindows())
                                   );
    pact->setEnabled(!ui->mdiArea->subWindowList().isEmpty());

    ui->menu_Windows->addSeparator();

    QList<QMdiSubWindow*> listDoc = ui->mdiArea->subWindowList();
    for (int i = 0; i < listDoc.size(); ++i) {
        pact = ui->menu_Windows->addAction(listDoc.at(i)->windowTitle());
        pact->setCheckable(true);
        pact->setChecked(ui->mdiArea->activeSubWindow() == listDoc.at(i));
        connect(pact, SIGNAL(triggered()), sigMap, SLOT(map()));
        sigMap->setMapping(pact, listDoc.at(i));
    }
}

void MDI8::slotSetActiveSubWindow(QWidget* pwgt)
{
    if (pwgt) {
        ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(pwgt));
    }

}




MDI8::~MDI8()
{
    delete ui;
}
