#include "sudokumodel.h"

SudokuModel::SudokuModel(QObject *parent) : QObject(parent)
{
    int i, j;

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            cell[i][j] = 0;
            cout << cell[i][j] << ' ';
        }
        cout << endl;
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

    qDebug() << "File opening";
    inputStream.open(filename);
    qDebug() << "File opened";

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            inputStream >> num;
            cell[i][j] = num-'0';
            cout << cell[i][j] << ' ';
        }
        cout << endl;
    }

    qDebug() << "File loaded";

    inputStream.close();

    emit sig_initDisplay();
}
