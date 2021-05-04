#include "supprimerprof.h"
#include "ui_supprimerprof.h"
#include <QMessageBox>

supprimerprof::supprimerprof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerprof)
{
    ui->setupUi(this);
}

supprimerprof::~supprimerprof()
{
    delete ui;
}

void supprimerprof::on_pushButton_clicked()
{
    login connecter;
    QString idp;

    idp=ui->txt_IDP->text();

    if(!connecter.Ouvrirdb()){
        qDebug()<<"échec d'ouverture";
        return;
    }
    connecter.Ouvrirdb();
    QSqlQuery qry;
    qry.prepare("Delete from Professeur where IDP='"+idp+"'");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Supprimer"),tr("Supprimé"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
