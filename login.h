#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QFile>
#include "menu.h"
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    void Fermerdb(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool Ouvrirdb(){
        QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/HP/Documents/db.db");
        if(!mydb.open()){
             qDebug()<<("Echec de se connecter à la base de données");
             return false;}
        else {
             qDebug()<<("Se connecter...");
             return true;}
    }
public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;

};
#endif // LOGIN_H
