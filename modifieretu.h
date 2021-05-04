#ifndef MODIFIERETU_H
#define MODIFIERETU_H

#include <QDialog>
#include "login.h"


namespace Ui {
class Modifieretu;
}

class Modifieretu : public QDialog
{
    Q_OBJECT

public:
    explicit Modifieretu(QWidget *parent = nullptr);
    ~Modifieretu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Modifieretu *ui;
};

#endif // MODIFIERETU_H
