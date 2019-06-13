#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

#include "include_file.h"

enum Border { left_side, right_side, top_side, bottom_side };

class SudokuCell : public QFrame
{
    Q_OBJECT
public:
    explicit SudokuCell(QFrame *parent = nullptr);
    void enableBorder(const Border &border);
    void initialiseState(int value);
    void init_ID(int i_value, int j_value);
    void solverStateUpdate(int value);

signals:
    void sig_stateUpdate(const int &value, const int &i, const int &j);

public slots:

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    int state;
    int i_id, j_id;

    bool initialised_cell;

    bool left_border_enable;
    bool right_border_enable;
    bool top_border_enable;
    bool bottom_border_enable;
};

#endif // SUDOKUCELL_H
