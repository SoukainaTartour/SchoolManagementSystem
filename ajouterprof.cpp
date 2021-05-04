#include "ajouterprof.h"
#include "ui_ajouterprof.h"
#include <QMessageBox>
ajouterprof::ajouterprof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterprof)
{
    ui->setupUi(this);
}

ajouterprof::~ajouterprof()
{
    delete ui;
}

void ajouterprof::on_pushButton_clicked()
{
    login connecter;
    QString idp,nom,prenom,adresse,telephone,matiere;

    idp=ui->txt_IDP->text();
    nom=ui->txt_NOM->text();
    prenom=ui->txt_PRENOM->text();
    adresse=ui->txt_ADRESSE->text();
    telephone=ui->txt_TELEPHONE->text();
    matiere=ui->txt_MATIERE->text();


    if(!connecter.Ouvrirdb()){
        qDebug()<<"échec d'ouverture";
        return;
    }
    connecter.Ouvrirdb();
    QSqlQuery qry;
    qry.prepare("insert into Professeur (IDP,Nom,Prénom,Adresse,Téléphone,Matière) values ('"+idp+"','"+nom+"','"+prenom+"','"+adresse+"','"+telephone+"','"+matiere+"')");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Enregistrer"),tr("Enregistré"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
