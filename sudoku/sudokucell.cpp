#include "sudokucell.h"

SudokuCell::SudokuCell(QWidget *parent) : QWidget(parent), state(0), left_border_enable(false), right_border_enable(false), top_border_enable(false), bottom_border_enable(false)
{
    /* Empty */
}

void SudokuCell::enableBorder(const Border &border)
{
    switch(border)
    {
    case left_side:
        left_border_enable = true;
        break;
    case right_side:
        right_border_enable = true;
        break;
    case top_side:
        top_border_enable = true;
        break;
    case bottom_side:
        bottom_border_enable = true;
        break;
    }
}

void SudokuCell::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QFont font;

    font.setPixelSize(height()/2);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setFont(font);

    /*
    painter.drawLine(QPoint(0, 0), QPoint(width(), 0));
    painter.drawLine(QPoint(width(), 0), QPoint(width(), height()));
    painter.drawLine(QPoint(width(), height()), QPoint(0, height()));
    painter.drawLine(QPoint(0, height()), QPoint(0, 0));
    */

    if ( left_border_enable )
    {
        painter.drawLine(QPoint(0, 0), QPoint(0, height()));
    }

    if ( right_border_enable )
    {
        painter.drawLine(QPoint(width(), 0), QPoint(width(), height()));
    }

    if ( top_border_enable )
    {
        painter.drawLine(QPoint(0, 0), QPoint(width(), 0));
    }

    if ( bottom_border_enable )
    {
        painter.drawLine(QPoint(0, height()), QPoint(width(), height()));
    }

    painter.drawText(rect(), Qt::AlignCenter, QString::number(state));
}

void SudokuCell::mousePressEvent(QMouseEvent *event)
{
    if ( event->button()==Qt::LeftButton )
    {
        if ( ++state>9 )
        {
            state = 0;
        }
    }

    else if ( event->button()==Qt::RightButton )
    {
        if ( --state<0 )
        {
            state = 9;
        }
    }

    else
    {
        qDebug() << "Some other button pressed";
    }
    //qDebug() << "state = " << state;
    update();
}
