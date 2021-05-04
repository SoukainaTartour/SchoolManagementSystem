#include "ajouteretudiant.h"
#include "ui_ajouteretudiant.h"
#include <QMessageBox>
#include <QFile>
#include <QSqlQuery>
ajouteretudiant::ajouteretudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouteretudiant)
{
    ui->setupUi(this);
    login connecter;

    if(!connecter.Ouvrirdb())
         ui->label_reconnect->setText("Failed to open the database");
    else
         ui->label_reconnect->setText("Connected...");
}

ajouteretudiant::~ajouteretudiant()
{
    delete ui;
}

void ajouteretudiant::on_pushButton_clicked()
{
    login connecter;
    QString ide,cne,nom,prenom,telephone,date_naissance,filiere;

    ide=ui->txt_ID->text();
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
    qry.prepare("insert into Etudiant (IDE,CNE,Nom,Prénom,Téléphone,DateN,Filière) values ('"+ide+"','"+cne+"','"+nom+"','"+prenom+"','"+telephone+"','"+date_naissance+"','"+filiere+"')");
    if(qry.exec()){
       QMessageBox::critical(this,tr("Enregistrer"),tr("Enregistré"));
       connecter.Fermerdb();
    }
    else{
       QMessageBox::critical(this,tr("Erreur::"),qry.lastError().text());
    }
}
