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
    ~SudokuModel() override;

    void initGrid(string filename);
    void updateCell(int i, int j, int value);
    int getCellValue(int i, int j);

signals:
    void sig_initDisplay(void);
    void sig_solverStateUpdate(const int &value, const int &i, const int &j);

public slots:
    int sudokuSolver(void);

private:
    int cell[9][9];

    int *possibleNum(int i, int j);
    int fullGrid(void);
    int checkCol(int i);
    int checkRow(int j);
};

#endif // SUDOKUMODEL_H
