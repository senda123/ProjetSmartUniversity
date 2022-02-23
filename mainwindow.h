#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "reservation.h"
#include <QMediaPlayer>
#include <QCompleter>
#include <QSystemTrayIcon>
#include "arduino.h"
namespace Ui {
class MainWindow;
}

class QSqlTableModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_admin_clicked();

    void on_enseignant_clicked();

    void on_ajouterS_clicked();

    void on_afficherS_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_supprimerS_clicked();

    void on_pushButton_2_clicked();

    void on_update_clicked();

    void on_pushButton_3_clicked();

    void on_update1_clicked();
    void update_label();


    void on_pushButton_4_clicked();



private:
    Ui::MainWindow *ui;
    reservation tmpR;
    QHeaderView *m_horiz_header;
    QHeaderView *m_horiz_header1;
    QMediaPlayer *media;
    QSystemTrayIcon * notif;
    QCompleter * comp;
    Arduino A;

    QByteArray data;
    QString serialBuffer;


};

#endif // MAINWINDOW_H
