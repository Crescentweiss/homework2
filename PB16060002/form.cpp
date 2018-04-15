#include "form.h"
#include "ui_form.h"
#include "setting.h"
#include "ui_setting.h"
#include "form.h"
#include "ui_form.h"
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>
#include <QStringList>
#include <QDebug>
#include <QDateTime>
#include<QApplication>
#include<dll.h>
#include<QLibrary>


using namespace std;

//static int i=1;
//static int j=0;
int flag=0;
QString ques[1000],ans[1000];
static int m=0,n=0,l=0,max=0,score=0;
QFile er("d:\\error.txt");
QFile hi("d:\\history.txt");
QFile ti("d:\\produce_q.txt");
QFile da("d:\\produce_a.txt");
QFile sc("d:\\score.txt");


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lcdNumber->display(20);
   // connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(History()));
   // connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Score()));
   // connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Wrong()));
   //connect(ui->lcdNumber,SIGNAL(clicked()),this,SLOT(Timeslot()));
    //QTimer *timer = new QTimer(this);
    // connect(ui->lcdNumber,SIGNAL(clicked()),this,SLOT(Timeslot()));
   // connect(timer, SIGNAL(timeout()), this, SLOT(Timeslot()));
   // timer->start(1000);
   // timerId=startTimer(1000);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_5_clicked()
{
    QLibrary mylib("D:/XDATA/QTTTTTTTT/build-test-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/Core.dll");
    typedef void (*Fun1)();
    typedef bool (*Fun2)(const char*);
    if(mylib.load())
    {
        //QMessageBox::information(this,tr("afasfa"),tr("传统美德"));
        Fun1 open=(Fun1)mylib.resolve("generate");
        if(open)
        {
             open();
             Fun2 put=(Fun2)mylib.resolve("exp_to_File");
             if(put)
             {
                 put("D:\\produce_q.txt");
             }
        }
    }

 //   m=0;n=0;l=0;score=0;
    if(!da.open(QIODevice::ReadOnly |QIODevice::Text))
         qDebug()<<da.errorString();
     QTextStream in_0(&da);
     while(!in_0.atEnd()){
         QString line_1=in_0.readLine();
         ans[l]=line_1; //qDebug()<<ans[l];
         l++;
     }
   da.close();
   if(!ti.open(QIODevice::ReadOnly |QIODevice::Text))
       qDebug()<<ti.errorString();
   QTextStream in_1(&ti);
   QString num;
   while(!in_1.atEnd())
   {
           QString line_2=in_1.readLine();
           num=QString ::number(m+1);
           ques[m]=num+". "+line_2;
           m++;
   }
   ti.close();
   if(!er.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<er.errorString();
   if(!hi.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<hi.errorString();
   if(!sc.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<sc.errorString();
   ui->label_3->setText(ques[0]);
   timerId = startTimer(1000);   // 1s
      ui->stackedWidget->setCurrentIndex(1); //翻页
}

void Form::on_pushButton_4_clicked()
{
    QTextStream out_1(&hi);
    if(ui->answer1->text() == ans[n])
    {
        score++;
        out_1<<ques[n]<<ui->answer1->text()<<endl;
    }
    else{
        QTextStream out(&er);
        QString inf = QString(" (错误！答案应为%1)").arg(ans[n]);
        out<<ques[n]<<ui->answer1->text()<<inf<<endl;
        QString inf_1 = QString(" (错误！)");
        out_1<<ques[n]<<ui->answer1->text()<< inf_1<<endl;
    }
    n++;
    if(m==n)//题目数-1；
    {
        QString str = QString("恭喜！您答对了 %1 题！").arg(score);
        QMessageBox::information(this, "得分", str);

              QTextStream out_2(&sc);
              QString score_1;
              score_1="正确率：";
              out_2<<score_1;
              score_1=QString ::number(score);
              out_2<<score_1<<'/';
              score_1=QString ::number(n);
              out_2<<score_1<<endl;
              killTimer(this->timerId);
        this->hide();
//        setting->show();
        End->show();
    }
    ui->label_3->setText(ques[n]);
    ui->answer1->setText("");
     ui->answer1->setFocus();
    ui->lcdNumber->display(20);

}
/*
void Form::Timeslot()
{

    ui->lcdNumber->display(ui->lcdNumber->value()-1);    //时间递减
    if(ui->lcdNumber->value()==0){
         QMessageBox::information(this,tr("超时"),tr("已超时"));
        ui->lcdNumber->display(20);
    }
}
*/
void Form::timerEvent(QTimerEvent *event)
{
    ui->lcdNumber->display(ui->lcdNumber->value() - 1);
    if(ui->lcdNumber->value()==0){

        QMessageBox::information(this,tr("超时"),tr("已超时"));
        QTextStream out_1(&hi);
        if(ui->answer1->text() == ans[n])
        {
            score++;
            out_1<<ques[n]<<ui->answer1->text()<<endl;
        }
        else{
            QTextStream out(&er);
            QString inf = QString(" (错误！答案应为%1)").arg(ans[n]);
            out<<ques[n]<<ui->answer1->text()<<inf<<endl;
            QString inf_1 = QString(" (错误！)");
            out_1<<ques[n]<<ui->answer1->text()<< inf_1<<endl;
        }
      n++;                                               //计数+1
      if(n==m)//题目数-1；
      {
          QString str = QString("恭喜！您答对了 %1 题！").arg(score);
          QMessageBox::information(this, "得分", str);

                QTextStream out_2(&sc);
                QString score_1;
                score_1=QString ::number(score);
                out_2<<score_1<<endl;
          killTimer(this->timerId);
          this->hide();
          End->show();
      }
      ui->label_3->setText(ques[n]);
      ui->answer1->setText("");
      ui->answer1->setFocus();

        ui->lcdNumber->display(20);

    }
}

