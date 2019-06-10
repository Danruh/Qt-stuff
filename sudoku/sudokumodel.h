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

signals:

public slots:

private:
    int cell[9][9];
};

#endif // SUDOKUMODEL_H
