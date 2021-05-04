#ifndef SUPPRIMERPROF_H
#define SUPPRIMERPROF_H

#include <QDialog>
#include "login.h"

namespace Ui {
class supprimerprof;
}

class supprimerprof : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerprof(QWidget *parent = nullptr);
    ~supprimerprof();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supprimerprof *ui;
};

#endif // SUPPRIMERPROF_H
