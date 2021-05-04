#ifndef MATIERES_H
#define MATIERES_H

#include <QDialog>
#include "ajoutermatiere.h"
#include "modifierma.h"
#include "supprimerma.h"

namespace Ui {
class matieres;
}

class matieres : public QDialog
{
    Q_OBJECT

public:
    explicit matieres(QWidget *parent = nullptr);
    ~matieres();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::matieres *ui;
};

#endif // MATIERES_H
