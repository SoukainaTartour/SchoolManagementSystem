#ifndef AJOUTERMATIERE_H
#define AJOUTERMATIERE_H

#include <QDialog>
#include "login.h"
namespace Ui {
class ajoutermatiere;
}

class ajoutermatiere : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutermatiere(QWidget *parent = nullptr);
    ~ajoutermatiere();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ajoutermatiere *ui;
};

#endif // AJOUTERMATIERE_H
