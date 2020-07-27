#include "fen_cloture.h"
#include "ui_fen_cloture.h"

fen_cloture::fen_cloture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_cloture)
{
    ui->setupUi(this);
    QStringList titulos;
    titulos << "Date";
    titulos << "Reference";
    titulos << "Titre";
    titulos << "Comptes";
    titulos << "Debit";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);//colocar titulos
}

fen_cloture::~fen_cloture()
{
    delete ui;
}
