#include "fen_supprimercompte.h"
#include "ui_fen_supprimercompte.h"
#include "CompteManager.h"


fen_Supprimercompte::fen_Supprimercompte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_Supprimercompte)
{
    ui->setupUi(this);

    //ui->Affichage_solde->display(solde);
}

fen_Supprimercompte::~fen_Supprimercompte()
{
    delete ui;
}

void fen_Supprimercompte::on_buttonBox_accepted()
{
    accept();
}

void fen_Supprimercompte::on_buttonBox_rejected()
{
    reject();
}

int fen_Supprimercompte::GetSolde() {

}
