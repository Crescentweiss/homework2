#include "history.h"
#include "ui_history.h"
#include <QFile>
#include<QFileInfo>
#include<QStringList>
#include<QDebug>
#include<QDateTime>
#include<QTextCodec>
#include<QString>







history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
}

history::~history()
{
    delete ui;
}

QFile ls("d:\\history.txt");

void history::on_show_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    if(!ls.open(QIODevice::ReadOnly |QIODevice::Text))
     qDebug()<<ls.errorString();

    QTextStream in(&ls);
    QString ss="";
    while(!in.atEnd()){
        QString line=in.readLine();
        ss=ss+line+"\n";

       }
    ui->textEdit->setText(ss);
    ls.close();
}

