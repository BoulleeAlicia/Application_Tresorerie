#ifndef FEN_SUPPRIMERCOMPTE_H
#define FEN_SUPPRIMERCOMPTE_H

#include <QDialog>


namespace Ui {
class fen_Supprimercompte;
}

class fen_Supprimercompte : public QDialog
{
    Q_OBJECT

public:
    explicit fen_Supprimercompte(QWidget *parent = nullptr);
    ~fen_Supprimercompte();
    int GetSolde();
    Ui::fen_Supprimercompte* getUI(){ return ui; }

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:

    Ui::fen_Supprimercompte* ui;
};

#endif // FEN_SUPPRIMERCOMPTE_H
