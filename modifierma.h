#ifndef MODIFIERMA_H
#define MODIFIERMA_H

#include <QDialog>
#include "login.h"

namespace Ui {
class modifierma;
}

class modifierma : public QDialog
{
    Q_OBJECT

public:
    explicit modifierma(QWidget *parent = nullptr);
    ~modifierma();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifierma *ui;
};

#endif // MODIFIERMA_H
