#include "fen_releves.h"
#include "ui_fen_releves.h"

fen_releves::fen_releves(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_releves)
{
    ui->setupUi(this);
    QStringList titulos;
    titulos << "Date";
    titulos << " ";
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);//colocar titulos
}

fen_releves::~fen_releves()
{
    delete ui;
}
