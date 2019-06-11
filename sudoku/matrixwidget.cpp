#include "matrixwidget.h"

MatrixWidget::MatrixWidget(QFrame *parent) : QFrame(parent)
{
    int i, j;
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);

    setAutoFillBackground(true);
    setPalette(pal);

    setFrameStyle( QFrame::Box | QFrame::Sunken );
    setLineWidth(1);

    grid = new QGridLayout(this);

    for ( i=0;i<9;i++ )
    {
        for ( j=0;j<9;j++ )
        {
            cell[i][j] = new SudokuCell;
            cell[i][j]->setFrameStyle( QFrame::StyledPanel | QFrame::Plain );
            cell[i][j]->setLineWidth(1);

            cell[i][j]->setAutoFillBackground(true);
            cell[i][j]->setPalette(pal);

            grid->addWidget(cell[i][j], i, j);

            if ( j==2 || j==5 || j==8 )
            {
                cell[i][j]->enableBorder(right_side);
            }
            if ( j==0 || j==3 || j==6 )
            {
                cell[i][j]->enableBorder(left_side);
            }
            if ( i==2 || i==5 || i==8 )
            {
                cell[i][j]->enableBorder(bottom_side);
            }
            if ( i==0 || i==3 || i==6 )
            {
                cell[i][j]->enableBorder(top_side);
            }
        }
    }
    grid->setSpacing(0);
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

