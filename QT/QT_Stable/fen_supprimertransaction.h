#ifndef FEN_SUPPRIMERTRANSACTION_H
#define FEN_SUPPRIMERTRANSACTION_H

#include <QDialog>
#include "TransactionManager.h"

namespace Ui {
class fen_supprimertransaction;
}

class fen_supprimertransaction : public QDialog
{
    Q_OBJECT

public:
    int getReference() const;
    explicit fen_supprimertransaction(QWidget *parent = nullptr);
    ~fen_supprimertransaction();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::fen_supprimertransaction *ui;
};

#endif // FEN_SUPPRIMERTRANSACTION_H
