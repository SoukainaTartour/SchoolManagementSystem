#include "supprimeretu.h"
#include "ui_supprimeretu.h"
#include <QMessageBox>
Supprimeretu::Supprimeretu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimeretu)
{
    ui->setupUi(this);
}

Supprimeretu::~Supprimeretu()
{
    delete ui;
}

void Supprimeretu::on_Suppimer_clicked()
{
    login connecter;
    QString ide,cne,nom,prenom,telephone,date_naissance,filiere;

    ide=ui->txt_IDE->text();

    if(!connecter.Ouvrirdb()){
        qDebug()<<"échec d'ouverture";
        return;
    }
    connecter.Ouvrirdb();
    QSqlQuery qry;
    qry.prepare("Delete from Etudiant where IDE='"+ide+"'");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Supprimer"),tr("Supprimé"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
