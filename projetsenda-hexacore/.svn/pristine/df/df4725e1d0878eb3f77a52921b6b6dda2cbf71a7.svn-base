#ifndef MAILING_H
#define MAILING_H
#include <QMainWindow>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QDialog>


namespace Ui {
class Mailing;
}

class Mailing : public QDialog
{
    Q_OBJECT

public:
    explicit Mailing(QWidget *parent = nullptr);
    ~Mailing();

private slots:

    void sendMail();
    void mailSent(QString);

private:
    Ui::Mailing *ui;
};

#endif // MAILING_H
