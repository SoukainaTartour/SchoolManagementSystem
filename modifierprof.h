#ifndef MODIFIERPROF_H
#define MODIFIERPROF_H

#include <QDialog>
#include "login.h"
namespace Ui {
class modifierprof;
}

class modifierprof : public QDialog
{
    Q_OBJECT

public:
    explicit modifierprof(QWidget *parent = nullptr);
    ~modifierprof();

private slots:
    void on_pushButton_Modifier_clicked();

private:
    Ui::modifierprof *ui;
};

#endif // MODIFIERPROF_H
