#include "etudiants.h"
#include "ui_etudiants.h"
#include <QTableView>

Etudiants::Etudiants(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Etudiants)
{
    ui->setupUi(this);
}

Etudiants::~Etudiants()
{
    delete ui;
}

void Etudiants::on_pushButton_clicked()
{
    this->hide();
    ajouteretudiant ajout;
    ajout.setModal(true);
    ajout.exec();
}


void Etudiants::on_pushButton_Modifier_clicked()
{
    this->hide();
    Modifieretu modifier;
    modifier.setModal(true);
    modifier.exec();
}




void Etudiants::on_pushButton_Supprimer_clicked()
{
    this->hide();
    Supprimeretu supprimer;
    supprimer.setModal(true);
    supprimer.exec();
}

void Etudiants::on_pushButton_2_clicked()
{
    login connecter;
    QSqlQueryModel * modal=new QSqlQueryModel();
    connecter.Ouvrirdb();
    QSqlQuery* qry=new QSqlQuery(connecter.mydb);
    qry->prepare("select * from Etudiant");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    connecter.Fermerdb();
    qDebug()<<(modal->rowCount());
}
