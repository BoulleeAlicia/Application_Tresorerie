#ifndef FEN_NEWCOMPTE_H
#define FEN_NEWCOMPTE_H

#include <QDialog>
#include <QComboBox>
#include <QDate>
#include <QTreeView>
#include "CompteManager.h"

namespace Ui {
class fen_newcompte;
}

class fen_newcompte : public QDialog
{
    Q_OBJECT

public:
    explicit fen_newcompte(QWidget *parent = nullptr);
    ~fen_newcompte();

    QString getCompte_parent() const;
    QString getType_compte() const;
    QString getNom_compte() const;
    QString getVirtuel() const;
    double getSolde() const;

private slots:
    void on_box_compteParent_currentIndexChanged(const QString &arg1);


    void on_newCompte_OK_accepted();

    void on_newCompte_OK_rejected();

    void afficher_comptes(vector<Compte*> f);

private:
    Ui::fen_newcompte *ui;
};

#endif // FEN_NEWCOMPTE_H
