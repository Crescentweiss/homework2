#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include<QTimerEvent>
#include<end.h>
#include<ui_end.h>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);

    ~Form();

protected:
    void timerEvent(QTimerEvent *event);

private slots:
  void on_pushButton_5_clicked();
  void on_pushButton_4_clicked();

private:
    Ui::Form *ui;
    int timerId;
    end *End=new end;
    QButtonGroup *changepage;


};

#endif // FORM_H
