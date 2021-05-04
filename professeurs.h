#ifndef PROFESSEURS_H
#define PROFESSEURS_H

#include <QDialog>
#include "ajouterprof.h"
#include "modifierprof.h"
#include "supprimerprof.h"
namespace Ui {
class professeurs;
}

class professeurs : public QDialog
{
    Q_OBJECT

public:
    explicit professeurs(QWidget *parent = nullptr);
    ~professeurs();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::professeurs *ui;
};

#endif // PROFESSEURS_H
