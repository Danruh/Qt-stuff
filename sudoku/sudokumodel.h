#ifndef SUDOKUMODEL_H
#define SUDOKUMODEL_H
#include "include_file.h"

/* TODO:

 * - Link the cell matrix to the sudokucell widgets
 * - Some more menus and stuff
 * - Implement the solving algorithm
 */

class SudokuModel : public QObject
{
    Q_OBJECT
public:
    explicit SudokuModel(QObject *parent = nullptr);

    void initGrid(string filename);
    void updateCell(int i, int j, int value);
    int getCellValue(int i, int j);

signals:
    void sig_initDisplay(void);

public slots:
    int sudokuSolver(int &lol);

private:
    int cell[9][9];

    int *possibleNum(int i, int j);
};

#endif // SUDOKUMODEL_H
