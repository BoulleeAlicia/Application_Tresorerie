#ifndef FEN_NEWTRANSACTION_H
#define FEN_NEWTRANSACTION_H

#include <QDialog>
#include "CompteManager.h"
#include "Operation.h"

namespace Ui {
class fen_newtransaction;
}

class fen_newtransaction : public QDialog
{
    Q_OBJECT

public:
    explicit fen_newtransaction(QWidget *parent = nullptr);
    ~fen_newtransaction();
    QString getMemo() const;
    int getReference() const;
    QDate getDate() const;
    vector<Operation*> getOperations();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_clicked();

    void on_newTransanction_debit_valueChanged(double arg1);

    void on_newTransanction_credit_valueChanged(double arg1);

private:
    Ui::fen_newtransaction *ui;

    vector<Operation*> op;

    void afficher_comptes_source(vector<Compte*> f);

    void afficher_comptes_destination(vector<Compte*> f);
};

#endif // FEN_NEWTRANSACTION_H
