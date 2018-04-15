#ifndef END_H
#define END_H

#include <QWidget>

namespace Ui {
class end;
}

class end : public QWidget
{
    Q_OBJECT

public:
    explicit end(QWidget *parent = 0);
    ~end();

private slots:
    void on_back_clicked();
    void on_score_clicked();
    void on_error_clicked();
    void on_close_clicked();
    void on_history_clicked();

private:
    Ui::end *ui;

};

#endif // END_H
