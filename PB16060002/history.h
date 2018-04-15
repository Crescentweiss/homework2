#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>

namespace Ui {
class history;
}

class history : public QWidget
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = 0);
    ~history();

private slots:
    void on_show_clicked();

private:
    Ui::history *ui;
};

#endif // HISTORY_H
