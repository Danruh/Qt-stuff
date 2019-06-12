#include "sudokumodel.h"

SudokuModel::SudokuModel(QObject *parent) : QObject(parent)
{
    int i, j;

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            cell[i][j] = 0;
        }
    }
}

int SudokuModel::getCellValue(int i, int j)
{
    return cell[i][j];
}

void SudokuModel::initGrid(string filename)
{
    fstream inputStream;
    char num;
    int i, j;

    inputStream.open(filename);

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            inputStream >> num;
            cell[i][j] = num-'0';
        }
    }

    inputStream.close();

    emit sig_initDisplay();
}

void SudokuModel::updateCell(int i, int j, int value)
{
    cell[i][j] = value;
}


/* Public slots */
