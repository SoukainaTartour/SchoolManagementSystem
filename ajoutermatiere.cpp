#include "ajoutermatiere.h"
#include "ui_ajoutermatiere.h"
#include <QMessageBox>

ajoutermatiere::ajoutermatiere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutermatiere)
{
    ui->setupUi(this);
}

ajoutermatiere::~ajoutermatiere()
{
    delete ui;
}

void ajoutermatiere::on_pushButton_clicked()
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
    qry.prepare("insert into Matière (ID,Libellé) values ('"+id+"','"+libelle+"')");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Enregistrer"),tr("Enregistré"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
