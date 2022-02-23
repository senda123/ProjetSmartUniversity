#include "sallle.h"
#include <QSqlQuery>
#include <QDebug>

salle::salle()
{
    NUM_S=0;
    ETAT_S=0;

}


salle::salle(int NUM_S,int ETAT_S)
{
    this->NUM_S=NUM_S ;
    this->ETAT_S=ETAT_S;
}

int salle::get_Num_S()
{
    return NUM_S;
}

int salle::get_Etat_S()
{
    return ETAT_S;
}

bool salle::ajouter()
{
    QSqlQuery qry ;
    QString res= QString::number(ETAT_S);
    QString res1= QString::number(NUM_S);

        qry.prepare("INSERT INTO SALLE (NUM_S,ETAT_S)"
                    " VALUES (:NUM_S,:ETAT_S)");
        qry.bindValue(":NUM_S",res);
        qry.bindValue(":ETAT_S",res1);


    return qry.exec();

}

QSqlQueryModel *salle::afficher()
{
    QSqlQueryModel *model =new QSqlQueryModel();

     model->setQuery("select * from SALLE");
    return model;
}

bool salle::supprimer(int numS)
{
    QSqlQuery qry;
    QString ress=QString::number(numS);
    qry.prepare("Delete from SALLE where NUM_S=:NUM_S");
    qry.bindValue(":NUM_S",ress);
    return qry.exec();
}

bool salle::modifier()
{

    QString ress1= QString::number(NUM_S);
    QString ress2= QString::number(ETAT_S);
    QSqlQuery edit;

    edit.prepare("update SALLE set NUM_S=:NUM_S,ETAT_S=:ETAT_S where NUM_S=:NUM_S");
                      edit.bindValue(":NUM_S",ress1);
                      edit.bindValue(":ETAT_S",ress2);
                      return    edit.exec();
}

QSqlTableModel *salle::tri(int num )
{

   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("SALLE");

   mmodel->setSort(num,Qt::DescendingOrder);
   mmodel->select();
   return mmodel;



}
