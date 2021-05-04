#include "modifieretu.h"
#include "ui_modifieretu.h"
#include <QMessageBox>

Modifieretu::Modifieretu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifieretu)
{
    ui->setupUi(this);
}

Modifieretu::~Modifieretu()
{
    delete ui;
}

void Modifieretu::on_pushButton_clicked()
{
    login connecter;
    QString ide,cne,nom,prenom,telephone,date_naissance,filiere;

    ide=ui->txt_IDE->text();
    cne=ui->txt_CNE->text();
    nom=ui->txt_NOM->text();
    prenom=ui->txt_PRENOM->text();
    telephone=ui->txt_TELEPHONE->text();
    date_naissance=ui->txt_DATEN->text();
    filiere=ui->txt_FILIERE->text();

    if(!connecter.Ouvrirdb()){
        qDebug()<<"échec d'ouverture";
        return;
    }
    connecter.Ouvrirdb();
    QSqlQuery qry;
    qry.prepare("update Etudiant set IDE='"+ide+"',Nom='"+nom+"',Prénom='"+prenom+"',Téléphone='"+telephone+"',Date de naissance='"+date_naissance+"',Filière='"+filiere+"' where IDE='"+ide+"'");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Modifier"),tr("Modifié"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
