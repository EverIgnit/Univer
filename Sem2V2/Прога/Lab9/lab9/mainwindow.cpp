#include "mainwindow.h"
#include "ui_graphics.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    colorDlg = new QColorDialog(this);

    penStyle = new QComboBox;
    QStringList styles;
    styles << "Solid Line" << "Dash Dot Dot Line" << "Dash Line" << "Dot Line" << "Dash Dot Line" << "No Pen";
    penStyle->addItems(styles);
    ui->toolBar->addWidget(penStyle);

    brushStyle = new QComboBox;
    /*typedef QPair<QString, QBrush> BrushPair;
    foreach (const BrushPair &pair, QList<BrushPair>()
                     << qMakePair(tr("No Brush"), QBrush(Qt::NoBrush))
                     << qMakePair(tr("Solid"), QBrush(Qt::SolidPattern))
                     << qMakePair(tr("Dense #1"), Qt::Dense1Pattern)
                     << qMakePair(tr("Dense #2"), Qt::Dense2Pattern)
                     << qMakePair(tr("Dense #3"), Qt::Dense3Pattern)
                     << qMakePair(tr("Dense #4"), Qt::Dense4Pattern)
                     << qMakePair(tr("Dense #5"), Qt::Dense5Pattern)
                     << qMakePair(tr("Dense #6"), Qt::Dense6Pattern)
                     << qMakePair(tr("Dense #7"), Qt::Dense7Pattern)
                     << qMakePair(tr("Horizontal"), Qt::HorPattern)
                     << qMakePair(tr("Vertical"), Qt::VerPattern)
                     << qMakePair(tr("Cross"), Qt::CrossPattern)
                     << qMakePair(tr("Diagonal /"), Qt::BDiagPattern)
                     << qMakePair(tr("Diagonal \\"), Qt::FDiagPattern)
                     << qMakePair(tr("Diagonal Cross"), Qt::DiagCrossPattern))
    brushStyle->addItem(pair.first,pair.second);
    */
    QStringList brStyle;
    brStyle << "No Brush" <<"Solid"<<"Dense #1" << "Horisontal" << "Vertical" << "Cross" << "Diagonal /" << "Diagonal \\" << "DiagonalCross";
    brushStyle->addItems(brStyle);

    penSize = new QSpinBox;
    penSize->setRange(0,1000);
    penSize->setValue(3);
    ui->toolBar->addWidget(penSize);
    colorDlg->setCurrentColor(Qt::black);

    brushDlg= new QColorDialog(this);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(brushStyle);

    connect(ui->action_Pen,SIGNAL(triggered()),this,SLOT(openDlg()));
    connect(ui->action_Brush,SIGNAL(triggered()),this,SLOT(openBruh()));
    connect(ui->actionPolygon,SIGNAL(triggered()),this,SLOT(clrArr()));
    connect(ui->actionLine,SIGNAL(triggered()),this,SLOT(clrArr()));
    connect(ui->actionRect,SIGNAL(triggered()),this,SLOT(clrArr()));
    connect(ui->actionElipse,SIGNAL(triggered()),this,SLOT(clrArr()));
    connect(ui->action_Image_Fill,SIGNAL(toggled(bool)),this,SLOT(fileOpen()));

}

void MainWindow::clrArr()
{
    sub_size=0;
    arr_size=0;
    coords.clear();
    coords={{0,77},{0,77}};
}

void MainWindow::openDlg()
{
    colorDlg->open();

}

void MainWindow::openBruh()
{
    brushDlg->open();

}


void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter body(this);
    if(penStyle->currentIndex()==0)
        curPen= QPen(colorDlg->currentColor(),penSize->value(),Qt::SolidLine);
    else if(penStyle->currentIndex()==1)
        curPen= QPen(colorDlg->currentColor(),penSize->value(),Qt::DashDotDotLine);
    else if(penStyle->currentIndex()==2)
        curPen= QPen(colorDlg->currentColor(),penSize->value(),Qt::DashLine);
    else if(penStyle->currentIndex()==3)
        curPen= QPen(colorDlg->currentColor(),penSize->value(),Qt::DotLine);
    else if(penStyle->currentIndex()==4)
        curPen= QPen(colorDlg->currentColor(),penSize->value(),Qt::DashDotLine);
    else if(penStyle->currentIndex()==5)
        curPen= QPen(colorDlg->currentColor(),penSize->value(),Qt::NoPen);


    body.setPen(curPen);

    //    brStyle << "No Brush" <<"Solid"<<"Dense #1" << "Horisontal" << "Vertical" << "Cross" << "Diagonal /" << "Diagonal \\" << "DiagonalCross";

    if(brushStyle->currentIndex()==0)
        bruh = QBrush(brushDlg->currentColor(),Qt::NoBrush);
    else if(brushStyle->currentIndex()==1)
        bruh = QBrush(brushDlg->currentColor(),Qt::SolidPattern);
    else if(brushStyle->currentIndex()==2)
        bruh = QBrush(brushDlg->currentColor(),Qt::Dense1Pattern);
    else if(brushStyle->currentIndex()==3)
        bruh = QBrush(brushDlg->currentColor(),Qt::HorPattern);
    else if(brushStyle->currentIndex()==4)
        bruh = QBrush(brushDlg->currentColor(),Qt::VerPattern);
    else if(brushStyle->currentIndex()==5)
        bruh = QBrush(brushDlg->currentColor(),Qt::CrossPattern);
    else if(brushStyle->currentIndex()==6)
        bruh = QBrush(brushDlg->currentColor(),Qt::BDiagPattern);
    else if(brushStyle->currentIndex()==7)
        bruh = QBrush(brushDlg->currentColor(),Qt::FDiagPattern);
    else if(brushStyle->currentIndex()==8)
        bruh = QBrush(brushDlg->currentColor(),Qt::DiagCrossPattern);

    body.setBrush(bruh);
    if(arr_size%2==0)
        linGrad = QLinearGradient(coords[arr_size],coords[arr_size+1]);
    linGrad.setColorAt(0,brushDlg->currentColor());
    linGrad.setColorAt(1,colorDlg->currentColor());
    if(ui->action_Gradient->isChecked())
        body.setBrush(linGrad);
    if(ui->action_Image_Fill->isChecked())
        body.setBrush(pix);

    if(ui->actionLine->isChecked())
    {
        if(arr_size%2==0)
            body.drawLine(coords[arr_size],coords[arr_size+1]);

    }
    if(ui->actionRect->isChecked())
    {
        if(arr_size%2==0){
            tmpRect = QRectF(coords[arr_size],coords[arr_size+1]);
            body.drawRect(tmpRect);
        }
    }
    if(ui->actionElipse->isChecked()){
        if(arr_size%2==0)
        {
            tmpRect = QRectF(coords[arr_size],coords[arr_size+1]);
            body.drawEllipse(tmpRect);
        }
    }

    if(ui->actionPolygon->isChecked()){
        //arr_size=0;

        body.drawPolygon(crds, sub_size);
    }


}

void MainWindow::fileOpen()
{
    if(ui->action_Image_Fill->isChecked()){
    QFileDialog openDlg(this,"Image Open");
    openDlg.setAcceptMode(QFileDialog::AcceptOpen);
    openDlg.setFileMode(QFileDialog::ExistingFile);
    openDlg.setNameFilter(("Images (*.png *.xpm *.jpg *jpeg)"));
    if (openDlg.exec() != QDialog::Accepted)
        return;
    else {
        fileName = openDlg.selectedFiles();
    }

    pix = QPixmap(fileName[0]);
}
}


void MainWindow:: mousePressEvent(QMouseEvent* ev)
{
    crds[sub_size]=ev->pos();
    sub_size++;
    arr_size++;
    coords.push_back(ev->pos());


    update();
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    QString msg = "Coordinates: X() ";
    msg.append(QString::number(ev->x()));
    msg+="\tY() ";      msg.append(QString::number(ev->y()));

    ui->statusbar->showMessage(msg);
}
