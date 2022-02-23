#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QPixmap>
class connexion
{
public:
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QODBC");

    connexion();
    void fermerconnexion();
    bool ouvrirconnexion();
};

#endif // CONNEXION_H
