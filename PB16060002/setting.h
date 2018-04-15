#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

public slots:
    void confirm(); //确认参数设置

private slots:
    void on_pushButton_clicked();

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
