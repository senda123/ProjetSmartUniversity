#ifndef SALLLE_H
#define SALLLE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <connexion.h>

class salle
{

public:
    salle();
    salle(int,int);
    int get_Num_S();
    int get_Etat_S();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int numS);
    bool modifier();
    QSqlTableModel *tri(int num );

private:
    int NUM_S;
    int ETAT_S;

};

#endif // SALLLE_H
