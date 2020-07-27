#include "fen_touslescomptes.h"
#include "ui_fen_touslescomptes.h"

fen_touslesComptes::fen_touslesComptes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_touslesComptes)
{
    ui->setupUi(this);

    QStringList titulos;
    titulos << "Date";
    titulos << "Titre";
    titulos << "Comptes";
    titulos << "Debit";
    titulos << "Credit";
    ui->table_tous_comptes->setColumnCount(5);
    ui->table_tous_comptes->setHorizontalHeaderLabels(titulos);//colocar titulos
}

fen_touslesComptes::~fen_touslesComptes()
{
    delete ui;
}
