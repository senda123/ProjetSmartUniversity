#include "mainwindow.h"
#include "connexion.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include "sallle.h"
#include "mailing.h"
#include <QMediaPlayer>

int t=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->hide();
    QStringList tableidd ;
    tableidd << "ID";
    ui->tableWidget->setHorizontalHeaderLabels(tableidd);

    media = new QMediaPlayer ();
    media->setMedia( QUrl ("C:/Users/user/Desktop/Projet123/images123/song.mp3"));
    media->play();
    m_horiz_header=ui->tableView_2->horizontalHeader();
    m_horiz_header1=ui->tableView->horizontalHeader();
    QPixmap pix("C:/Users/user/Desktop/Projet123/images123/admin1.png");
    ui->bg->setPixmap(pix);
    QPixmap pix1("C:/Users/user/Desktop/Projet123/images123/enseignant1.png");
    ui->bg1->setPixmap(pix1);
notif= new QSystemTrayIcon(this);
notif ->setIcon(QIcon("C:/Users/user/Desktop/Projet123/images123/moins.png"));
    connect(m_horiz_header, SIGNAL(sectionClicked(int)),this,SLOT(on_update_clicked()));
    connect(m_horiz_header1, SIGNAL(sectionClicked(int)),this,SLOT(on_update1_clicked()));
    int ret=A.connect_arduino(); // lancer la connexion à arduino
      switch(ret){
      case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
          break;
      case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
         break;
      case(-1):qDebug() << "arduino is not available";
      }
       QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
       //le slot update_label suite à la reception du signal readyRead (reception des données).

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{

    int Num_R = ui->num->text().toInt();
    int Num_S = ui->numS->text().toInt();
     QDate  Date_R = ui->dateEdit->date();
     QString  Heure_R = ui->heure->text();
     reservation R(Num_R,Date_R,Heure_R,Num_S);
     if(R.ajouter())
     {

         qDebug() <<"hello";

     }
}

void MainWindow::on_afficher_clicked()
{

    reservation R;

    ui->tableView->setModel(R.afficher());


}

void MainWindow::on_supprimer_clicked()
{
    int Num_R=ui->num->text().toInt();
    reservation R;
    if (R.supprimer(Num_R))
    {
        ui->tableView->setModel(R.afficher());
    }
}

void MainWindow::on_modifier_clicked()
{
    int Num_R = ui->num->text().toInt();
     int Num_S = ui->numS->text().toInt();
      QDate Date_R = ui->dateEdit->date();
      QString Heure_R= ui->heure->text();
       reservation r(Num_R,Date_R,Heure_R,Num_S);
     r.modifier();
}

void MainWindow::update_label()
{

    QStringList bufferSplit =serialBuffer.split(",");

    if (serialBuffer.length()<8)
    {

        data=A.read_from_arduino();
     serialBuffer+= QString::fromStdString(data.toStdString());

    }
    else
    {
          qDebug () << serialBuffer;
        serialBuffer="";
    }


}


void MainWindow::on_admin_clicked()
{
    ui->user->setCurrentIndex(0);
}

void MainWindow::on_enseignant_clicked()
{
    ui->user->setCurrentIndex(1);

}

void MainWindow::on_ajouterS_clicked()
{

    int Etat_S = ui->etat->text().toInt();
    int Num_S = ui->numSalle->text().toInt();
    if (Etat_S!=0 && Etat_S!=1)
    {
        QMessageBox::critical(this,"Problème","Veuillez saisir 0 si la salle est  vide et 1 si elle est pleine");
    }
    else
    {
        salle S(Etat_S,Num_S);
        if(S.ajouter())
        {

            qDebug() <<"hello";

        }
    }


}

void MainWindow::on_afficherS_clicked()
{
    salle S;

    ui->tableView_2->setModel(S.afficher());



}

void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    reservation R ;
       if(ui->recherche->text().isEmpty())
       {

          ui->tableView->setVisible(false);
           QSqlQuery *query=new QSqlQuery("SELECT * from RESERVATION_SALLE");
           QSqlQueryModel *model=new QSqlQueryModel();
           model->setQuery(*query);
           ui->tableView->setModel(model);
           ui->tableView->show();
           ui->tableView->resizeColumnsToContents();
           ui->tableView->setVisible(true);

       }

       R.cleartable(ui->tableView);
       int Num_R =ui->recherche->text().toInt();
       R.rechercher(ui->tableView,Num_R);

       if(ui->recherche->text().isEmpty())
       {
           ui->tableView->setModel(tmpR.afficher());
       }

}

void MainWindow::on_pushButton_clicked()
{
    Mailing *m= new Mailing();
    m->show();
}

void MainWindow::on_supprimerS_clicked()
{
    int Num_S=ui->numSalle->text().toInt();
    salle S;
    if (S.supprimer(Num_S))
    {
        ui->tableView_2->setModel(S.afficher());
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    int ETAT_S = ui->etat->text().toInt();
    int NUM_S=ui->numSalle->text().toInt();

       salle S(NUM_S,ETAT_S);
     if(S.modifier())
         qDebug () << "hello";
}

void MainWindow::on_update_clicked()
{

    salle S;

  ui->tableView_2->setModel(S.tri(ui->tableView_2->currentIndex().column()));
}

void MainWindow::on_pushButton_3_clicked()
{
    salle S;

    ui->tableView->setModel(S.afficher());
    QSqlQuery qry;
           qry.prepare("select * from SALLE where ETAT_S=0");

    if (qry.exec())
    {
        while (qry.next())
        {

notif->showMessage("Notifications","Possibilité de réserver des salles (Il y a des salles vides) ",QSystemTrayIcon::Critical,10000);
notif->show();
break;
        }
    }
}

void MainWindow::on_update1_clicked()
{
    salle S;

  ui->tableView->setModel(S.tri(ui->tableView->currentIndex().column()));
}



void MainWindow::on_pushButton_4_clicked()
{
    if (serialBuffer.size()!=0)
   { ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(serialBuffer));
    A.write_to_arduino("1");
}
}


