#include "editor.h"
#include "ui_closer.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cmb = new QFontComboBox;

    ui->toolBar_fonts->insertWidget(nullptr,cmb);

    connect(ui->actionAbout_this,SIGNAL(triggered()),this,SLOT(about()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(fileSave()));
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(fileOpen()));
    connect(ui->actionSave_as,SIGNAL(triggered()),this,SLOT(fileSaveAs()));
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(fileNew()));
    connect(ui->textEditBody,SIGNAL(textChanged()),this,SLOT(slotStatusText()));

    connect(cmb,SIGNAL(currentFontChanged(const QFont &)),this,SLOT(slotFonts()));

    this->fileName = "MyFile";
    ui->statusbar->showMessage((tr("File directory: \"%1\"\tLines: %2").arg(fileName).arg(ui->textEditBody->document()->lineCount())));
    connect(ui->textEditBody->document(), &QTextDocument::modificationChanged, ui->actionSave, &QAction::setEnabled);
    connect(ui->textEditBody->document(), &QTextDocument::modificationChanged, this, &QWidget::setWindowModified);
    connect(ui->textEditBody->document(), &QTextDocument::undoAvailable, ui->actionUndo, &QAction::setEnabled);
    connect(ui->textEditBody->document(), &QTextDocument::redoAvailable, ui->actionRedo, &QAction::setEnabled);
    setWindowModified(ui->textEditBody->document()->isModified());
    ui->actionSave->setEnabled(ui->textEditBody->document()->isModified());
    ui->actionUndo->setEnabled(ui->textEditBody->document()->isUndoAvailable());
    ui->actionRedo->setEnabled(ui->textEditBody->document()->isRedoAvailable());

    connect(ui->statusbar,SIGNAL(messageChanged(const QString &)),this,SLOT(slotStatus()));

    dialog = new FindDialog(this);

    connect(ui->actionSearch, SIGNAL(triggered()),this,SLOT(showSearch()));
    connect(dialog,SIGNAL(sigSearch()),this,SLOT(findWord()));
    connect(dialog->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(slotCursor()));
    connect(dialog->searchSensitive,SIGNAL(clicked()),this,SLOT(slotCursor()));
    connect(dialog->searchUp,SIGNAL(clicked()),this,SLOT(slotCursor()));
    connect(dialog->searchDown,SIGNAL(clicked()),this,SLOT(slotCursor()));
}

void MainWindow::slotFonts(){
    QFont cur = cmb->currentFont();
    ui->textEditBody->setFont(cur);
}

void MainWindow::slotCursor()
{
    if(dialog->searchDown->isChecked())
    ui->textEditBody->moveCursor(QTextCursor::Start);
    else
    ui->textEditBody->moveCursor(QTextCursor::End);
}

void MainWindow::showSearch()
{
    dialog->show();
    ui->textEditBody->textCursor().setPosition(QTextCursor::Start);
}

void MainWindow::findWord(){

    const QString word = dialog->getFindText();

    if(dialog->searchUp->isChecked()){
        if(dialog->searchSensitive->isChecked())
            ui->textEditBody->find(word,QTextDocument::FindCaseSensitively | QTextDocument::FindBackward);
        else
             ui->textEditBody->find(word, QTextDocument::FindBackward);
    }
    else if(!dialog->searchUp->isChecked()){
        if(dialog->searchSensitive->isChecked())
             ui->textEditBody->find(word,QTextDocument::FindCaseSensitively);
        else
            ui->textEditBody->find(word);
    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (maybeSaved())
        e->accept();
    else
        e->ignore();
}

void MainWindow::slotStatus(){
    if(ui->statusbar->currentMessage().isEmpty()){
        ui->statusbar->showMessage(tr("File directory \"%1\"\twith %2 lines of text").arg(fileName).arg(ui->textEditBody->document()->lineCount()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about(){
    QMessageBox::about(this, "About...", "You can not say you don't like the programm btw\n☼☼Cause it's perfect☼☼\nNo rights reserved 2018-2019 ©HlebCorp ");
}

bool MainWindow::maybeSaved()
{
    if (!ui->textEditBody->document()->isModified())
        return true;
    const QMessageBox::StandardButton ret = QMessageBox::warning(this, QCoreApplication::applicationName(), tr("The document has been modified.\n" "Do you want to save changes?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
        return fileSave();
    else if (ret == QMessageBox::Cancel)
        return false;
    return true;
}

bool MainWindow::fileSave()
{
    if (fileName.isEmpty())
        return fileSaveAs();
    if (fileName.startsWith(QStringLiteral(":/")))
        return fileSaveAs();
    if (fileName=="MyFile") return fileSaveAs();

    QTextDocumentWriter writer(fileName);
    bool success = writer.write(ui->textEditBody->document());
    if (success) {
       ui->textEditBody->document()->setModified(false);
        statusBar()->showMessage(tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName)),1500);
    } else {
        statusBar()->showMessage(tr("Could not write to file \"%1\"").arg(QDir::toNativeSeparators(fileName)),1500);
    }
    return success;
}

bool MainWindow::fileSaveAs()
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
    return fileSave();
}

void MainWindow::setCurrentFileName(const QString &fileName)
{
    this->fileName = fileName;
    ui->textEditBody->document()->setModified(false);

    QString shownName;
    if (fileName.isEmpty())
        shownName = "MyFile.txt";
    else
        shownName = QFileInfo(fileName).fileName();

    setWindowTitle(tr("%1[*] - %2").arg(shownName, QCoreApplication::applicationName()));
    setWindowModified(false);
}

void MainWindow::fileOpen()
{
    if (maybeSaved()){
    QFileDialog fileDialog(this, tr("Open File..."));
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setMimeTypeFilters(QStringList() << "text/plain");
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fn = fileDialog.selectedFiles().first();
    if (load(fn))
        statusBar()->showMessage(tr("Opened \"%1\"").arg(QDir::toNativeSeparators(fn)),1500);
    else
         statusBar()->showMessage(tr("Could not open \"%1\"").arg(QDir::toNativeSeparators(fn)),1500);
    }
}

bool MainWindow::load(const QString &f)
{
    if (!QFile::exists(f))
        return false;
    QFile file(f);
    if (!file.open(QFile::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    QTextCodec *codec = Qt::codecForHtml(data);
    QString str = codec->toUnicode(data);
    if (Qt::mightBeRichText(str)) {
        ui->textEditBody->setHtml(str);
    } else {
        str = QString::fromLocal8Bit(data);
        ui->textEditBody->setPlainText(str);
    }

    setCurrentFileName(f);
    return true;
}

void MainWindow::fileNew()
{
    if (maybeSaved()) {
        ui->textEditBody->clear();
        setCurrentFileName(QString());
    }
}

void MainWindow::slotStatusText()
{
    ui->statusbar->showMessage("Text has been changed",1500);
}

FindDialog::FindDialog(QWidget *parent): QDialog(parent)
{
    setGeometry(800,500,400,100);
    QLabel *findLabel = new QLabel(tr("Enter search request:"));
    lineEdit = new QLineEdit;

    btnSearch = new QPushButton("&Search");
    findText = "";

    searchUp = new QRadioButton("Search &up");
    searchDown = new QRadioButton("Search &down");
    searchDown->setChecked(true);
    searchSensitive = new QCheckBox("&Case sensitive");
    searchSensitive->setChecked(false);
    QGridLayout *mylayout = new QGridLayout;

    mylayout->addWidget(findLabel,0,0,1,4);
    mylayout->addWidget(lineEdit, 1,0,1,5);
    mylayout->addWidget(btnSearch,2,4);
    mylayout->addWidget(searchSensitive,2,0);
    mylayout->addWidget(searchUp,2,1);
    mylayout->addWidget(searchDown,2,2);
    setLayout(mylayout);

    setWindowTitle("Search");

    connect(btnSearch,SIGNAL(clicked()),this,SLOT(findClicked()));
}

void FindDialog::findClicked()
{
    QString text = lineEdit->text();
        findText = text;
        text.clear();
        state=searchSensitive->isChecked();
    emit sigSearch();
}

QString FindDialog::getFindText()
{
    return findText;
}
