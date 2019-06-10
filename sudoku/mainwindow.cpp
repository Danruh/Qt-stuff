#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    matrix = new MatrixWidget;
    setCentralWidget(matrix);

    setWindowTitle("Sudoku - by Danruh");
    resize(500, 500);
}

MainWindow::~MainWindow()
{
    delete matrix;
}
