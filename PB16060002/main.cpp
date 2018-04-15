#include "mainwindow.h"
#include <QApplication>
#include "form.h"
#include "ui_form.h"
#include "setting.h"
#include "ui_setting.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form w;
    end w3;
    Setting w2;

    w2.show();
    return a.exec();

}
