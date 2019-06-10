#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "include_file.h"
#include "matrixwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    MatrixWidget *matrix;
};

#endif // MAINWINDOW_H
