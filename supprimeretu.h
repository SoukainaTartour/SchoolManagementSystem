#ifndef SUPPRIMERETU_H
#define SUPPRIMERETU_H

#include <QDialog>
#include "login.h"
namespace Ui {
class Supprimeretu;
}

class Supprimeretu : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimeretu(QWidget *parent = nullptr);
    ~Supprimeretu();

private slots:
    void on_Suppimer_clicked();

private:
    Ui::Supprimeretu *ui;
};

#endif // SUPPRIMERETU_H
