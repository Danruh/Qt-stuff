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
    initDockWidgets();
    connectSig_Slot();

    connect(model, &SudokuModel::sig_solverStateUpdate, matrix, &MatrixWidget::slot_solverStateUpdate);
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow destructor";
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

void MainWindow::slot_updateModel(const int &value, const int &i, const int &j)
{
    model->updateCell(i, j, value);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << "MainWindowHeight = " << height() << " matrix->height() = " << matrix->height();
    qDebug() << "MainWindowWidth = " << width() << " matrix->width() = " << matrix->width();
    if ( height()==(matrix->height()+63) )
    {
        setMaximumWidth( matrix->width()+158 );
    }
    else
    {
        setMaximumWidth( 16777215 );
    }
}

void MainWindow::createMenus()
{
    //toolBar = addToolBar("Quick buttons");
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
    /* Connect cell widgets to model */
    connect(matrix, &MatrixWidget::sig_updateModel, this, &MainWindow::slot_updateModel);

    connect(model, &SudokuModel::sig_initDisplay, this, &MainWindow::slot_initDisplay);
    connect(open, &QAction::triggered, this, &MainWindow::openGrid);
    connect(save, &QAction::triggered, this, &MainWindow::saveGrid);
}

void MainWindow::initDockWidgets(void)
{
    solverTools = new QDockWidget("Solver tools", this);
    solverButton = new QPushButton("Solve");
    solverTools->setWidget(solverButton);

    addDockWidget(Qt::RightDockWidgetArea, solverTools);

    connect(solverButton, &QPushButton::pressed, model, &SudokuModel::sudokuSolver);
}
