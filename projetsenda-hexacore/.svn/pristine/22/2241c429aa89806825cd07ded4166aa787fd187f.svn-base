#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QTimer>
#include <QtGui>
#include <QLabel>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

QLabel * label = new QLabel();

        label->setWindowFlags(Qt::FramelessWindowHint);

        label->setMask((new QPixmap("C:/Users/user/Desktop/Projet123/images123/giphy.gif"))->mask());

        QMovie *movie = new QMovie("C:/Users/user/Desktop/Projet123/images123/giphy.gif");

        label->setMovie(movie);

        movie->start();

        label->show();


        /*-*/


    connexion c;
    c.ouvrirconnexion();
    MainWindow *w = new MainWindow();
   QTimer::singleShot(2500,label,SLOT(close()));
   QTimer::singleShot(2500,w,SLOT(show()));




    return a.exec();
}
