#include "end.h"
#include "ui_end.h"
#include <form.h>
#include <ui_form.h>
#include "error.h"
#include "ui_error.h"
#include "score.h"
#include "ui_score.h"
#include "history.h"
#include "ui_history.h"

end::end(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);

    //connect(ui->back,SIGNAL(clicked()),this,SLOT(on_back_clicked()));
    //connect(ui->error,SIGNAL(clicked()),this,SLOT(on_error_clicked()));
    //connect(ui->score,SIGNAL(clicked()),this,SLOT(on_score_clicked()));
    //connect(ui->history,SIGNAL(clicked()),this,SLOT(on_history_clicked()));
}

end::~end()
{
    delete ui;
}

void end::on_back_clicked()
{
    Form *form=new Form;
    this->hide();
    form->show();
}

void end::on_error_clicked()
{
    error *ERROR=new error;
    ERROR->show();
}

void end::on_score_clicked()
{
    score *SCORE=new score;
    SCORE->show();
}

void end::on_history_clicked()
{
    history *HISTORY=new history;
    HISTORY->show();
}


void end::on_close_clicked()
{
    this->close();
}
