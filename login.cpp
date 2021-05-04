#include "login.h"
#include "ui_login.h"

#include <QPixmap>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    if(!Ouvrirdb())
         ui->label->setText("Echec d'ouverture de la base de données");
    else
         ui->label->setText("Se connecter...");
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    QString utilisateur,mdp;
    utilisateur=ui->lineEdit_utilisateur->text();
    mdp=ui->lineEdit_mdp->text();
    if(!Ouvrirdb()){
        qDebug()<<"échec d'ouverture";
        return;
    }
    Ouvrirdb();
    QSqlQuery qry;
    qry.prepare("select * from Utilisateur where utilisateur='"+utilisateur +"' and mdp='"+mdp+"'");
    if(qry.exec()){
        int count=0;
        while(qry.next()){
            count++;
        }
     if(count==1){
         ui->label->setText("Nom utilisateur et mot de passe sont correctes");
         Fermerdb();
         this->hide();
         menu m;
         m.setModal(true);
         m.exec();

     }

     if(count!=1)
         ui->label->setText("Nom utilisateur et mot de passe sont incorrectes");


    }


}
