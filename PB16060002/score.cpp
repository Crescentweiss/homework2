#include "score.h"
#include "ui_score.h"
#include<QFileInfo>
#include<QStringList>
#include<QDebug>
#include<QDateTime>
#include<QTextCodec>
#include<QString>

score::score(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::score)
{
    ui->setupUi(this);
}

score::~score()
{
    delete ui;
}

QFile cj("d:\\score.txt");

void score::on_show_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    if(!cj.open(QIODevice::ReadOnly |QIODevice::Text))
     qDebug()<<cj.errorString();

    QTextStream in(&cj);
    QString ss="";
    while(!in.atEnd()){
        QString line=in.readLine();
        ss=ss+line+"\n";

       }
    ui->textEdit->setText(ss);
    cj.close();
}
