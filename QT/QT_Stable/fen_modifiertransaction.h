#ifndef FEN_MODIFIERTRANSACTION_H
#define FEN_MODIFIERTRANSACTION_H

#include <QDialog>
#include "TransactionManager.h"
#include "CompteManager.h"
#include "Operation.h"

namespace Ui {
class fen_modifiertransaction;
}

class fen_modifiertransaction : public QDialog
{
    Q_OBJECT

public:
    explicit fen_modifiertransaction(QWidget *parent = nullptr);
    ~fen_modifiertransaction();
    QString getMemo() const;
    QDate getDate() const;
    int getReference() const;
    vector<Operation*> getOperations();
    vector<Operation*> new_op ;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::fen_modifiertransaction *ui;

    void afficher_comptes_source(vector<Compte*> f);

    void afficher_comptes_destination(vector<Compte*> f);
};

#endif // FEN_MODIFIERTRANSACTION_H
