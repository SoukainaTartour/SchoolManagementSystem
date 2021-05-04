#include "professeurs.h"
#include "ui_professeurs.h"
#include <QTableView>

professeurs::professeurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::professeurs)
{
    ui->setupUi(this);
}

professeurs::~professeurs()
{
    delete ui;
}

void professeurs::on_pushButton_clicked()
{
    this->hide();
    ajouterprof ajout;
    ajout.setModal(true);
    ajout.exec();
}

void professeurs::on_pushButton_2_clicked()
{
    this->hide();
    modifierprof modifier;
    modifier.setModal(true);
    modifier.exec();
}

void professeurs::on_pushButton_3_clicked()
{
    this->hide();
    supprimerprof supprimer;
    supprimer.setModal(true);
    supprimer.exec();
}

void professeurs::on_pushButton_4_clicked()
{
    login connecter;
    QSqlQueryModel * modal=new QSqlQueryModel();
    connecter.Ouvrirdb();
    QSqlQuery* qry=new QSqlQuery(connecter.mydb);
    qry->prepare("select * from Professeur");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    connecter.Fermerdb();
    qDebug()<<(modal->rowCount());
}
