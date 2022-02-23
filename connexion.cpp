#include "connexion.h"

connexion::connexion()
{

}

void connexion::fermerconnexion()
{
    mydb.close();
}

bool connexion::ouvrirconnexion()
{
    mydb.setDatabaseName("Source_Projet2A");
        mydb.setUserName("Senda");
        mydb.setPassword("senda08");
        if (mydb.open())
        {
            qDebug() <<"connect";
            return true;

        }
        else
        {
            qDebug () <<"failed";
            return false;
        }
}
