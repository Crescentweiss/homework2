#ifndef SET1_H
#define SET1_H

#include <QWidget>



namespace Ui {
class Set1;
}

class Set1 : public QWidget
{
    Q_OBJECT

public:
    explicit Set1(QWidget *parent = 0);
    ~Set1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Set1 *ui;
};

#endif // SET1_H
