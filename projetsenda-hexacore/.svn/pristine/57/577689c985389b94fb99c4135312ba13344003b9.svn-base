#include "reservation.h"
#include <QSqlQuery>
#include <QDebug>

reservation::reservation()
{
    Num_R=0 ;
    Date_R="" ;
    Heure_R="" ;
}

reservation::reservation(int num,QString date, QString heure,int numS)
{
    Num_R=num ;
    Date_R=date ;
    Heure_R=heure;
    Num_S=numS;

}

int reservation::get_Num_R()
{
    return Num_R;
}

int reservation::get_Num_S()
{
    return Num_S;
}
QString reservation::get_Date_R()
{
    return Date_R;
}
QString reservation::get_Heure_R()
{
    return Heure_R;
}

bool reservation::ajouter()
{

    QSqlQuery qry ;
    QString resnum= QString::number(Num_R);
    QString resnum1= QString::number(Num_S);

    qry.prepare("INSERT INTO RESERVATION_SALLE (Num_R,Date_R,Heure_R,Num_S)"
                " VALUES (:Num_R,:Date_R,:Heure_R,:Num_S)");
    qry.bindValue(":Num_R",Num_R);
    qry.bindValue(":Date_R",Date_R);
    qry.bindValue(":Heure_R",Heure_R);
    qry.bindValue(":Num_S",Num_S);
qDebug () << qry.lastError().text();
    return qry.exec();
}

QSqlQueryModel *reservation::afficher()
{
    QSqlQueryModel *model =new QSqlQueryModel();

     model->setQuery("select * from RESERVATION_SALLE");
    return model;
}

bool reservation::supprimer(int num)
{
    QSqlQuery qry;
    QString res=QString::number(num);
    qry.prepare("Delete from RESERVATION_SALLE where Num_R=:Num_R");
    qry.bindValue(":Num_R",res);
    return qry.exec();
}


bool reservation::modifier()
{

    QString resnum= QString::number(Num_R);
    QString resnum1= QString::number(Num_S);
    QSqlQuery edit;

    edit.prepare("update RESERVATION_SALLE set Num_R= :Num_R,Date_R=:Date_R,Heure_R=:Heure_R,Num_S=:Num_S where Num_R=:Num_R");
                      edit.bindValue(":Num_R",resnum);
                      edit.bindValue(":Num_S",resnum1);
                      edit.bindValue(":Date_R",Date_R);
                      edit.bindValue(":Heure_R",Heure_R);
                      return    edit.exec();
}



void reservation :: rechercher(QTableView * table ,int Num_R )
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from RESERVATION_SALLE where regexp_like(Num_R,:Num_R);");
    query->bindValue(":Num_R",Num_R);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void reservation::cleartable(QTableView * table)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->clear();
    table->setModel(model);

}


