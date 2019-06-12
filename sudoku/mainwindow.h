#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "include_file.h"
#include "matrixwidget.h"
#include "sudokumodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

signals:

public slots:
    void openGrid(void);
    void saveGrid(void);
    void slot_initDisplay(void);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;

    SudokuModel *model;
    MatrixWidget *matrix;

    /* Toolbar */
    QToolBar *toolBar;

    /* Menus */
    QMenu *fileMenu;

    /* Menu actions */
    QAction *open;
    QAction *save;
    QAction *quit;

    void createMenus(void);
    void connectSig_Slot(void);
};

#endif // MAINWINDOW_H
