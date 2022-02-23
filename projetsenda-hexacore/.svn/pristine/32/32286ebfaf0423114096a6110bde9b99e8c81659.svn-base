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
    reservation(int,QString,QString,int);
    int get_Num_R();
    int get_Num_S();
    QString get_Date_R();
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
    QString Date_R ;
    QString Heure_R ;



};

#endif // RESERVATION_H
