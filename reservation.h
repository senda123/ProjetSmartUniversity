#ifndef RESERVATION_H
#define RESERVATION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <connexion.h>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include<QTableView>
#include<QSqlTableModel>
class reservation
{
public:
    reservation();
    reservation(int,QDate,QString,int);
    int get_Num_R();
    int get_Num_S();
    QDate get_Date_R();
    QString get_Heure_R();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int num);
    bool modifier();
    void rechercher(QTableView * table ,int);
    void cleartable (QTableView * table);


private:
    int Num_R ;
    int Num_S;
    QDate Date_R ;
    QString Heure_R ;



};

#endif // RESERVATION_H
