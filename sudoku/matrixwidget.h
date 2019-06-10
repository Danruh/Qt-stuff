#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H
#include "include_file.h"
#include "sudokucell.h"
using namespace std;

class MatrixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixWidget(QWidget *parent = nullptr);
    ~MatrixWidget();

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QGridLayout *grid;
    SudokuCell *cell[9][9];
};

#endif // MATRIXWIDGET_H
