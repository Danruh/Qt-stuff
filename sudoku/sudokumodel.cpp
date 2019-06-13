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

SudokuModel::~SudokuModel()
{

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

int SudokuModel::sudokuSolver(void)
{
    int x, y, a;
    int i, j = 0;
    int *posPoint;
    int posNum[9];

    for ( a=0;a<9;a++ )
    {
        posNum[a] = 0;
    }

    if ( fullGrid()==0 )
    {

        return 0;
    }
    else
    {
        for ( x=0;x<9;x++ )
        {
            for ( y=0;y<9;y++ )
            {
                if ( cell[x][y]==0 )
                {
                    i = x;
                    j = y;
                    goto SOLVE;
                }
            }
        }
        SOLVE:
        // Get possible numbers
        posPoint = possibleNum(i, j);
        for ( a=0;a<9;a++)
        {
            posNum[a] = *(posPoint+a);
        }
        for ( x=0;x<9;x++ )
        {
            if ( posNum[x]!=0 )
            {
                cell[i][j] = posNum[x];
                emit sig_solverStateUpdate(posNum[x], i, j);
                //cout << "\n" << endl;
                sudokuSolver();
            }
        }
        cell[i][j] = 0;
    }
    return 1;
}

/* Private functions */

int *SudokuModel::possibleNum(int i, int j)
{
    static int possible_num_switch[9];
    int a, b, x, y;

    for( a=0;a<9;a++ ){ possible_num_switch[a]=0; }

    //Check if number exists in row
    for( a=0;a<9;a++ )
    {
        if( cell[i][a]!=0 )
        {
            possible_num_switch[cell[i][a]-1] = 1;
            //cout << possible_num_switch[grid[i][a]-1] << "\n";
        }
    }

    //Check if number exists in column
    for( a=0;a<9;a++ )
    {
        if ( cell[a][j] )
        {
            possible_num_switch[cell[a][j]-1] = 1;
        }
    }

    //Check in nonet

    x = checkCol(i);
    y = checkRow(j);
    //cout << x << y;
    for ( a=x;a<(x+3);a++ )
    {
        for ( b=y;b<(y+3);b++)
        {
            if ( cell[a][b] )
            {
                possible_num_switch[cell[a][b]-1] = 1;
            }
        }
    }

    for ( a=0;a<9;a++ )
    {
        if ( possible_num_switch[a]==0 )
        {
            possible_num_switch[a] = a+1;
        }
        else
        {
            possible_num_switch[a]= 0;
        }
    }

    return possible_num_switch;
}

int SudokuModel::fullGrid(void)
{
    int i, j;

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            if ( cell[i][j]==0 )
            {
                return 1;
            }
        }
    }
    return 0;
}

int SudokuModel::checkCol(int i)
{
    int x;

    if ( (0<=i) && (i<=2) )
    {
        x = 0;
    }
    else if ( (3<=i) && (i<=5) )
    {
        x = 3;
    }
    else
    {
        x = 6;
    }

    return x;
}

int SudokuModel::checkRow(int j)
{
    int y;

    if ( (0<=j) && (j<=2) )
    {
        y = 0;
    }
    else if ( (3<=j) && (j<= 5) )
    {
        y = 3;
    }
    else
    {
        y = 6;
    }

    return y;
}
