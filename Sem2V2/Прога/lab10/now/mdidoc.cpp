#include "mdidoc.h"
#include "ui_mdiDoc.h"

MDIDoc::MDIDoc(QMainWindow* parent) :
    QMainWindow (parent),
    ui(new Ui::MDIDoc)
{
    ui->setupUi(this);
    fileName = "¯\\_(ツ)_/¯";
    fontDlg = new QFontDialog(this);

    connect(ui->textEdit->document(), &QTextDocument::modificationChanged,
            ui->action_Save, &QAction::setEnabled);
    connect(ui->textEdit->document(), &QTextDocument::modificationChanged,
            ui->actionSave_as, &QAction::setEnabled);
    connect(ui->textEdit->document(), &QTextDocument::modificationChanged,
            this, &QWidget::setWindowModified);
    connect(ui->textEdit->document(), &QTextDocument::undoAvailable,
            ui->actionUndo, &QAction::setEnabled);
    connect(ui->textEdit->document(), &QTextDocument::redoAvailable,
            ui->actionRedo, &QAction::setEnabled);

    setWindowModified(ui->textEdit->document()->isModified());
    ui->actionSave_as->setEnabled(ui->textEdit->document()->isModified());
    ui->action_Save->setEnabled(ui->textEdit->document()->isModified());
    ui->actionUndo->setEnabled(ui->textEdit->document()->isUndoAvailable());
    ui->actionRedo->setEnabled(ui->textEdit->document()->isRedoAvailable());

    connect(ui->action_Save,SIGNAL(triggered()),SLOT(slotSave()));
    connect(ui->actionSave_as,SIGNAL(triggered()),SLOT(slotSaveAs()));

    connect(ui->textEdit,SIGNAL(textChanged()),SLOT(slotStatusText()));
    connect(ui->statusBar,SIGNAL(messageChanged(const QString &)),SLOT(slotStatusDir()));
    connect(ui->actionFonts,SIGNAL(triggered()),SLOT(slotFonts()));
}

void MDIDoc::slotStatusDir(){
    if(ui->statusBar->currentMessage().isEmpty()){

        ui->statusBar->showMessage(tr("File directory \"%1\"\tAmount of lines: %2").arg(fileName).arg(ui->textEdit->document()->lineCount()));
    }
}

void MDIDoc::slotStatusText()
{
    ui->statusBar->showMessage("Text Changed",1500);
}



// ----------------------------------------------------------------------
bool MDIDoc::slotSave()
{
    if (fileName=="¯\\_(ツ)_/¯") {
        return slotSaveAs();
    }

    QTextDocumentWriter writer(fileName);
    bool success = writer.write(ui->textEdit->document());
    if (success) {
       ui->textEdit->document()->setModified(false);

        statusBar()->showMessage(tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName)),1500);
    } else {
        statusBar()->showMessage(tr("Could not write to file \"%1\"")
                                 .arg(QDir::toNativeSeparators(fileName)),1500);
    }
        emit changeWindowTitle(fileName);
    return success;
}

// ----------------------------------------------------------------------
bool MDIDoc::slotSaveAs()
{
    QFileDialog fileDialog(this, tr("Save as..."));
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QStringList mimeTypes;
    mimeTypes << "text/plain";
    fileDialog.setMimeTypeFilters(mimeTypes);
    fileDialog.setDefaultSuffix("txt");
    if (fileDialog.exec() != QDialog::Accepted)
        return false;
    const QString fn = fileDialog.selectedFiles().first();
    setCurrentFileName(fn);
    return slotSave();
}

void MDIDoc::slotFonts()
{
    fontDlg->open();
    if(fontDlg->exec()==1)
        ui->textEdit->setFont(fontDlg->currentFont());

}

void MDIDoc::closeEvent(QCloseEvent *e)
{
    if (maybeSave())
        e->accept();
    else
        e->ignore();
}

bool MDIDoc::maybeSave()
{
    if (!ui->textEdit->document()->isModified())
        return true;

    const QMessageBox::StandardButton ret =
        QMessageBox::warning(this, QCoreApplication::applicationName(),
                             tr("The document has been modified.\n"
                                "Do you want to save your changes?"),
                             QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
        return slotSave();
    else if (ret == QMessageBox::Cancel)
        return false;
    return true;
}


void MDIDoc::setCurrentFileName(const QString &fileName)
{
    this->fileName = fileName;
    ui->textEdit->document()->setModified(false);

    QString shownName;
    if (fileName.isEmpty())
        shownName = "¯_(ツ)_¯.txt";
    else
        shownName = QFileInfo(fileName).fileName();

    setWindowTitle(tr("%1[*] - %2").arg(shownName, QCoreApplication::applicationName()));
    setWindowModified(false);
}

void MDIDoc::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()) {
        return;
    }

    QFile file(str);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        ui->textEdit->setPlainText(stream.readAll());
        file.close();

        fileName = str;
        emit changeWindowTitle(fileName);
    }
}

MDIDoc::~MDIDoc()
{
    delete ui;
}
