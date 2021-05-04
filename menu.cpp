#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    this->hide();
    Etudiants e;
    e.setModal(true);
    e.exec();
}

void menu::on_pushButton_2_clicked()
{
    this->hide();
    professeurs p;
    p.setModal(true);
    p.exec();
}

void menu::on_pushButton_3_clicked()
{
    this->hide();
    matieres m;
    m.setModal(true);
    m.exec();
}
