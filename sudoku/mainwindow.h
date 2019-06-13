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
    void slot_updateModel(const int &value, const int &i, const int &j);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;

    SudokuModel *model;
    MatrixWidget *matrix;

    /* QDockWidgets */
    QDockWidget *solverTools;

    /* Toolbar */

    /* Menus */
    QMenu *fileMenu;

    /* Pushbuttons */
    QPushButton *solverButton;

    /* Menu actions */
    QAction *open;
    QAction *save;
    QAction *quit;

    /* Dock widget actions */
    QAction *solve;

    void createMenus(void);
    void connectSig_Slot(void);
    void initDockWidgets(void);
};

#endif // MAINWINDOW_H
