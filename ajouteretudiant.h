#ifndef AJOUTERETUDIANT_H
#define AJOUTERETUDIANT_H

#include <QDialog>
#include "login.h"

namespace Ui {
class ajouteretudiant;
}

class ajouteretudiant : public QDialog
{
    Q_OBJECT

public:

    explicit ajouteretudiant(QWidget *parent = nullptr);
    ~ajouteretudiant();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ajouteretudiant *ui;
};

#endif // AJOUTERETUDIANT_H
