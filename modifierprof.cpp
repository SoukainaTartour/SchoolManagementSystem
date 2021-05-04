#include "modifierprof.h"
#include "ui_modifierprof.h"
#include <QMessageBox>

modifierprof::modifierprof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierprof)
{
    ui->setupUi(this);
}

modifierprof::~modifierprof()
{
    delete ui;
}

void modifierprof::on_pushButton_Modifier_clicked()
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
    qry.prepare("update Professeur set IDP='"+idp+"',Nom='"+nom+"',Prénom='"+prenom+"',Adresse='"+adresse+"',Téléphone='"+telephone+"',Matière='"+matiere+"' where IDP='"+idp+"'");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Modifier"),tr("Modifié"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
