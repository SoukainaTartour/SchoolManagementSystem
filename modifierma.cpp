#include "modifierma.h"
#include "ui_modifierma.h"
#include <QMessageBox>

modifierma::modifierma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierma)
{
    ui->setupUi(this);
}

modifierma::~modifierma()
{
    delete ui;
}

void modifierma::on_pushButton_clicked()
{
    login connecter;
    QString id,libelle;

    id=ui->txt_ID->text();
    libelle=ui->txt_LIBELLE->text();


    if(!connecter.Ouvrirdb()){
        qDebug()<<"échec d'ouverture";
        return;
    }
    connecter.Ouvrirdb();
    QSqlQuery qry;
    qry.prepare("update Matière set ID='"+id+"',Libellé='"+libelle+"' where ID='"+id+"'");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Modifier"),tr("Modifié"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
