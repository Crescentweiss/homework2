#include "setting.h"
#include "ui_setting.h"
#include "form.h"
#include "ui_form.h"
#include "set1.h"
#include "ui_set1.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QStringList>
#include <QDateTime>
#include <QTextCodec>
#include <QLibrary>
#include "dll.h"


using namespace std;

typedef void(*Fun)(int,int,int,int,int);
typedef void(*Fun1)();
typedef bool(*Fun2)(int,string,string);
typedef void (*Fun3)(bool, bool, bool, bool, bool);
typedef void (*Fun4)(bool);
typedef bool (*Fun5)(const char*);
typedef bool (*Fun6)(const char*);
typedef void (*Fun7)(int);

QLibrary mylib("Core.dll");

extern int ques_num, oper_max, oper_num, oper_kind, prec, flag_1;
extern bool ad, su, mu, di, po;

QFile xt("d:\\produce_q.txt"),xa("d:\\produce_a.txt");

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
    Set1 *widget = new Set1();
    //this->hide();
    widget->show();
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

   if(flag_1 == 0)
   {
       ad=1;
       su=1;
       mu=1;
       di=1;
       po=0;
   }
   int m=1;  //qDebug()<<oper_kind<<ad<<su<<mu<<di<<po;
   std::string strq="ques",stra="ans";
   if(!xt.open(QIODevice::WriteOnly |QIODevice::Text))
       qDebug()<<xt.errorString();
   if(!xa.open(QIODevice::WriteOnly |QIODevice::Text))
       qDebug()<<xa.errorString();
   QTextStream out_6(&xt);
   QTextStream out_7(&xa);
   QString strq_1,stra_1;
   const char* exp="D:/produce_q.txt";
   const char* ans="D:/produce_a.txt";

   if(mylib.load())
   {
       Fun set=(Fun)mylib.resolve("?set@@YAXHHHHH@Z");
       Fun1 generate=(Fun1)mylib.resolve("?generate@@YAXXZ");
       Fun2 get_exp=(Fun2)mylib.resolve("?get_exp@@YA_NHAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z");
       Fun3 set_opr=(Fun3)mylib.resolve("?set_opr@@YAX_N0000@Z");
       Fun4 set_power_signal=(Fun4)mylib.resolve("?set_power_signal@@YAX_N@Z");
       Fun5 exp_to_file=(Fun5)mylib.resolve("?exp_to_file@@YA_NPBD@Z");
       Fun6 ans_to_file=(Fun6)mylib.resolve("?ans_to_file@@YA_NPBD@Z");
       Fun7 set_precision=(Fun7)mylib.resolve("?set_precision@@YAXH@Z");

       set(oper_max, oper_num, ques_num, oper_kind, prec);   //set_precision(value5);
       set_opr(ad,su,mu,di,po);
       set_power_signal(true);
       generate();
       exp_to_file(exp);
       ans_to_file(ans);


   }
   (&xt)->close();
   (&xa)->close();
   this->hide();
   widget->show();
}
