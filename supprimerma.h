#ifndef SUPPRIMERMA_H
#define SUPPRIMERMA_H

#include <QDialog>
#include "login.h"

namespace Ui {
class supprimerma;
}

class supprimerma : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerma(QWidget *parent = nullptr);
    ~supprimerma();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supprimerma *ui;
};

#endif // SUPPRIMERMA_H
