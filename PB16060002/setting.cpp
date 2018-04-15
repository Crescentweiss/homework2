#include "setting.h"
#include "ui_setting.h"
#include "form.h"
#include "ui_form.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QLibrary>


int num_max;    //操作数的最大值
int num_limit;  //操作数的最大个数
int exp_num;    //表达式个数
int type;   //操作数类型
int precision;   //小数精度


Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(confirm()));
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_pushButton_clicked()
{
    QLibrary lib("D:/XDATA/QTTTTTTTT/build-test-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/Core10.dll");
    bool x;
    if(lib.load()){
        typedef bool(*Func)(int,int,int,int,QString,bool,int);
        typedef void(*func)();
        Func set=(Func)lib.resolve("setting");
        func getR=(func)lib.resolve("getResultFile");
        if(set){
            x =set(10,4,1,20,"+-*/^",true,3);
            getR();
        }
        if(x == false){
            QMessageBox::information(this,tr("afasfa"),tr("传统美德"));
        }
    }
/*
    bool ok;
    num_max=QInputDialog::getInt(this, tr(""), tr("数字最大值:请输入1~32767以内的整数"),1000,1,32767,50,&ok);
    if(ok) qDebug()<<"操作数的最大值:"<<num_max;

    num_limit=QInputDialog::getInt(this, tr(""), tr("操作数数量:请输入1~32767以内的整数"),20,1,32767,50,&ok);
    if(ok) qDebug()<<"操作数最大个数:"<<num_limit;

    exp_num=QInputDialog::getInt(this, tr(""), tr("题目数量:请输入1~32767以内的整数"),5,1,32767,100,&ok);
    if(ok) qDebug()<<"题目数量:"<<exp_num;

    type=QInputDialog::getInt(this, tr(""), tr("计算类型:请输入0（小数）、1（整数）、2（分数）"),0,0,2,1,&ok);
    if(ok) qDebug()<<"计算类型:"<<type;

    precision=QInputDialog::getInt(this, tr(""), tr("小数精度:请输入1~32767以内的整数"),2,1,32767,1,&ok);
    if(ok) qDebug()<<"操作数的最大值:"<<precision;
*/

}

void Setting::confirm()
{
   Form *widget = new Form();
   this->hide();
   widget->show();
}
