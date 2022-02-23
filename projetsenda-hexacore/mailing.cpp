#include "mailing.h"
#include "ui_mailing.h"

Mailing::Mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mailing)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

void Mailing::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text() , "smtp.gmail.com" , 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail(ui->uname->text(),ui->rcpt->text()  , ui->subject->text() , ui->msg->toPlainText());
}

Mailing::~Mailing()
{
    delete ui;
}
