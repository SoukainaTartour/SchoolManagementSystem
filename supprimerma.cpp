#include "supprimerma.h"
#include "ui_supprimerma.h"
#include <QMessageBox>

supprimerma::supprimerma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerma)
{
    ui->setupUi(this);
}

supprimerma::~supprimerma()
{
    delete ui;
}

void supprimerma::on_pushButton_clicked()
{
    login connecter;
    QString id;

    id=ui->txt_ID->text();

    if(!connecter.Ouvrirdb()){
        qDebug()<<"échec d'ouverture";
        return;
    }
    connecter.Ouvrirdb();
    QSqlQuery qry;
    qry.prepare("Delete from Matière where ID='"+id+"'");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Supprimer"),tr("Supprimé"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
