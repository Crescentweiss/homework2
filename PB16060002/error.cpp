#include "error.h"
#include "ui_error.h"
#include<QFileInfo>
#include<QStringList>
#include<QDebug>
#include<QDateTime>
#include<QTextCodec>
#include<QString>

error::error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::error)
{
    ui->setupUi(this);

    connect(ui->show,SIGNAL(clicked()),this,SLOT(on_show_clicked()));
}

error::~error()
{
    delete ui;
}
QFile ww("d:\\error.txt");

void error::on_show_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    if(!ww.open(QIODevice::ReadOnly |QIODevice::Text))
     qDebug()<<ww.errorString();

    QTextStream in(&ww);
    QString ss="";
    while(!in.atEnd()){
        QString line=in.readLine();
        ss=ss+line+"\n";

       }
    ui->textEdit->setText(ss);
    ww.close();


}
