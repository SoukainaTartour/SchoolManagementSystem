#include "matieres.h"
#include "ui_matieres.h"
#include <QTableView>

matieres::matieres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matieres)
{
    ui->setupUi(this);
}

matieres::~matieres()
{
    delete ui;
}

void matieres::on_pushButton_clicked()
{
    this->hide();
    ajoutermatiere ajout;
    ajout.setModal(true);
    ajout.exec();
}

void matieres::on_pushButton_2_clicked()
{
    this->hide();
    modifierma modifier;
    modifier.setModal(true);
    modifier.exec();
}

void matieres::on_pushButton_3_clicked()
{
    this->hide();
    supprimerma supprimer;
    supprimer.setModal(true);
    supprimer.exec();
}

void matieres::on_pushButton_4_clicked()
{
    login connecter;
    QSqlQueryModel * modal=new QSqlQueryModel();
    connecter.Ouvrirdb();
    QSqlQuery* qry=new QSqlQuery(connecter.mydb);
    qry->prepare("select * from Matière");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    connecter.Fermerdb();
    qDebug()<<(modal->rowCount());
}
