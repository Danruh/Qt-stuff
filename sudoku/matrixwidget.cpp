#include "matrixwidget.h"

MatrixWidget::MatrixWidget(QWidget *parent) : QWidget(parent)
{
    int i, j;
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);

    grid = new QGridLayout(this);

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            cell[i][j] = new SudokuCell;
            cell[i][j]->setAutoFillBackground(true);
            cell[i][j]->setPalette(pal);
            grid->addWidget(cell[i][j], i, j);

            if ( j==2 || j==5 )
            {
                cell[i][j]->enableBorder(right_side);
            }
            if ( j==3 || j==6 )
            {
                cell[i][j]->enableBorder(left_side);
            }
            if ( i==2 || i==5 )
            {
                cell[i][j]->enableBorder(bottom_side);
            }
            if ( i==3 || i==6 )
            {
                cell[i][j]->enableBorder(top_side);
            }
        }
    }
    grid->setSpacing(1);
}

MatrixWidget::~MatrixWidget()
{
    int i, j;
    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            delete cell[i][j];
        }
    }
    delete grid;
}

void MatrixWidget::resizeEvent(QResizeEvent *event)
{
    int newlength = qMin(width(), height());
    resize(newlength, newlength);
}

