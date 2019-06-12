#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new SudokuModel;
    matrix = new MatrixWidget;

    setCentralWidget(matrix);

    setWindowTitle("Sudoku - by Danruh");
    resize(500, 500);

    createMenus();
    connectSig_Slot();
}

MainWindow::~MainWindow()
{
    delete matrix;
    delete model;

    delete fileMenu;
    delete open;
    delete save;
    delete quit;
}

/* Public Slots
 *
 */

void MainWindow::openGrid(void)
{
    QString filename = QFileDialog::getOpenFileName(this, tr("What file do you wanna open bitch"), QString(), tr("Text files (*.txt)"));

    cout << filename.toStdString() << endl;

    model->initGrid(filename.toStdString());
}

void MainWindow::saveGrid(void)
{
    qDebug() << "saveGrid() says TO DO";
}

void MainWindow::slot_initDisplay(void)
{
    int i, j;

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            if ( model->getCellValue(i, j) )
            {
                matrix->initCell(i, j, model->getCellValue(i, j));
            }
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if ( height()==matrix->height() )
    {
        setMaximumWidth(matrix->width());
    }
}

void MainWindow::createMenus()
{
    //toolBar = new QToolBar(this);
    fileMenu = menuBar()->addMenu("File");

    open = new QAction("Open", this);
    save = new QAction("Save", this);
    quit = new QAction("Quit", this);

    fileMenu->addAction(open);
    fileMenu->addAction(save);
    fileMenu->addAction(quit);
}

void MainWindow::connectSig_Slot(void)
{
    qDebug() << "connectSig_Slot(void)";

    connect(model, &SudokuModel::sig_initDisplay, this, &MainWindow::slot_initDisplay);
    connect(open, &QAction::triggered, this, &MainWindow::openGrid);
    connect(save, &QAction::triggered, this, &MainWindow::saveGrid);
}
