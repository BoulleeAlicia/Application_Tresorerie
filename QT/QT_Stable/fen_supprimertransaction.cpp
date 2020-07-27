#include "fen_supprimertransaction.h"
#include "ui_fen_supprimertransaction.h"
#include<QDebug>

fen_supprimertransaction::fen_supprimertransaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_supprimertransaction)
{
    ui->setupUi(this);

    QStringList titulos;
    titulos << "Memo";
    titulos << "Reference";
    titulos << "Date";
    titulos << "Marque";
    setWindowTitle("Comptes");
    ui->tableWidget_trans->setColumnCount(4);
    ui->tableWidget_trans->setHorizontalHeaderLabels(titulos);//colocar titulos

    TransactionManager& tm = TransactionManager::getInstance();
    tm.afficherTransactionsQT(ui->tableWidget_trans);
    tm.afficherSurQcombobox(ui->Transactions);
}

fen_supprimertransaction::~fen_supprimertransaction()
{
    delete ui;
}

void fen_supprimertransaction::on_buttonBox_accepted()
{
    accept();
}

void fen_supprimertransaction::on_buttonBox_rejected()
{
    reject();
}

int fen_supprimertransaction::getReference() const{
    return (ui->Transactions->itemText(ui->Transactions->currentIndex())).toInt();
}

