#ifndef AJOUTERPROF_H
#define AJOUTERPROF_H

#include <QDialog>
#include "login.h"
namespace Ui {
class ajouterprof;
}

class ajouterprof : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterprof(QWidget *parent = nullptr);
    ~ajouterprof();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ajouterprof *ui;
};

#endif // AJOUTERPROF_H
