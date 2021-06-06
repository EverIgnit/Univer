#pragma once
#include <QMainWindow>
#include <QAction>
#include <QFontComboBox>
#include <QDialog>
#include <QtWidgets>
#include <QStatusBar>
#include <QFont>
namespace Ui {
    class  MainWindow;
}

class FindDialog : public QDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = nullptr);
    QString getFindText();
    QCheckBox* searchSensitive;
    QRadioButton* searchUp;
    QRadioButton* searchDown;
    QPushButton* btnSearch;
    QLineEdit* lineEdit;
    QString findText;
    int state;
public  slots:
    void findClicked();
        signals:
    void sigSearch();
    friend class MainWindow;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    bool load(const QString &f);
    ~MainWindow() override;

    QDialog* search;
    Ui::MainWindow *ui;
private:
    bool maybeSaved();

    QString fileName;
    void setCurrentFileName(const QString &fileName);
    FindDialog *dialog;
    QFontComboBox* cmb;

protected:
    void closeEvent(QCloseEvent *e) override;

public slots:
    void fileNew();
    void findWord();
    void showSearch();
    void about();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void slotStatusText();
    void slotStatus();
    void slotFonts();
    void slotCursor();

    friend class FindDialog;
};
