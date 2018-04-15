#ifndef SCORE_H
#define SCORE_H

#include <QWidget>

namespace Ui {
class score;
}

class score : public QWidget
{
    Q_OBJECT

public:
    explicit score(QWidget *parent = 0);
    ~score();

private slots:
    void on_show_clicked();

private:
    Ui::score *ui;
};

#endif // SCORE_H
