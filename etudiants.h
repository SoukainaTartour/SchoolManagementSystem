#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <QDialog>
#include "ajouteretudiant.h"
#include "modifieretu.h"
#include "supprimeretu.h"
namespace Ui {
class Etudiants;
}

class Etudiants : public QDialog
{
    Q_OBJECT

public:
    explicit Etudiants(QWidget *parent = nullptr);
    ~Etudiants();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Modifier_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Etudiants *ui;
};

#endif // ETUDIANTS_H
