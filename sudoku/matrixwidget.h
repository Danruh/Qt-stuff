#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H
#include "include_file.h"
#include "sudokucell.h"
using namespace std;

class MatrixWidget : public QFrame
{
    Q_OBJECT
public:
    explicit MatrixWidget(QFrame *parent = nullptr);
    ~MatrixWidget() override;

    void initCell(int i, int j, int value);
signals:
    void sig_updateModel(const int &value, const int &i, const int &j);

public slots:
    void slot_stateUpdate(const int &value, const int &i, const int &j);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QGridLayout *grid;
    SudokuCell *cell[9][9];

    void connectCells_Matrix(void);
};

#endif // MATRIXWIDGET_H
