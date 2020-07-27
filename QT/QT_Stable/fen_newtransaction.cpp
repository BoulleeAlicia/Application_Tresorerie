#include "fen_newtransaction.h"
#include "ui_fen_newtransaction.h"
#include "mainwindow.h"

fen_newtransaction::fen_newtransaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_newtransaction)
{
    ui->setupUi(this);
    CompteManager& c = CompteManager::getInstance();
    CompteRacine& r = c.getRacine();
    vector<Compte*> fils = r.getFils();
    QString::fromStdString(r.getNom());
    afficher_comptes_source(fils);
    afficher_comptes_destination(fils);
    QStringList titulos;
    titulos << "Compte";
    titulos << "Debit";
    titulos << "Credit";
    setWindowTitle("Transaction");
    ui->tableWidget_trans->setColumnCount(3);
    ui->tableWidget_trans->setHorizontalHeaderLabels(titulos);
}

fen_newtransaction::~fen_newtransaction()
{
    delete ui;
}

void fen_newtransaction::afficher_comptes_source(vector<Compte*> f){
    if(f.size()==0) return;
    CompteVirtuel* v;
    QString nom;
    for(std::vector<Compte*>::iterator it=f.begin();it!=f.end();it++){
        if((*it)->getTypeCompte() == virtuel){
            v = dynamic_cast<CompteVirtuel*>((*it));
            afficher_comptes_source(v->getFils());
        }
        else if((*it)->getTypeCompte() == reel){
            nom = QString::fromStdString((*it)->getNom());
            ui->newTransaction_Source->addItem(nom);
        }
    }
}

void fen_newtransaction::afficher_comptes_destination(vector<Compte*> f){
    if(f.size()==0) return;
    CompteVirtuel* v;
    QString nom;
    for(std::vector<Compte*>::iterator it=f.begin();it!=f.end();it++){
        if((*it)->getTypeCompte() == virtuel){
            v = dynamic_cast<CompteVirtuel*>((*it));
            afficher_comptes_destination(v->getFils());
        }
        else if((*it)->getTypeCompte() == reel){
            nom = QString::fromStdString((*it)->getNom());
            ui->newTransaction_Destination->addItem(nom);
        }
    }
}

void fen_newtransaction::on_buttonBox_accepted()
{
    accept();
}

void fen_newtransaction::on_buttonBox_rejected()
{
    reject();
}


QString fen_newtransaction::getMemo() const{
    return ui->newTransaction_memo->text();
}
int fen_newtransaction::getReference() const{
    return ui->newTransaction_reference->value();
}
QDate fen_newtransaction::getDate() const{
    return ui->newTransaction_date->date();
}
vector<Operation*> fen_newtransaction::getOperations(){
    return op;
}

void fen_newtransaction::on_pushButton_clicked()
{
    QString source = ui->newTransaction_Source->itemText(ui->newTransaction_Source->currentIndex());
    QString destination = ui->newTransaction_Destination->itemText(ui->newTransaction_Destination->currentIndex());
    double credit = ui->newTransanction_credit->value();
    double debit = ui->newTransanction_debit->value();

    CompteManager& c = CompteManager::getInstance();
    Operation* op1 = new Operation(debit, credit, dynamic_cast<CompteReel&> (c.getCompteByNom(destination.toStdString())));
    Operation* op2 = new Operation(credit, debit, dynamic_cast<CompteReel&> (c.getCompteByNom(source.toStdString())));
    op.push_back(op1);
    op.push_back(op2);

    ui->tableWidget_trans->insertRow(ui->tableWidget_trans->rowCount());
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 0, new QTableWidgetItem (destination));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 1, new QTableWidgetItem (QString::number(debit)));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 2, new QTableWidgetItem (QString::number(credit)));

    ui->tableWidget_trans->insertRow(ui->tableWidget_trans->rowCount());
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 0, new QTableWidgetItem (source));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 1, new QTableWidgetItem (QString::number(credit)));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 2, new QTableWidgetItem (QString::number(debit)));

}

void fen_newtransaction::on_newTransanction_debit_valueChanged(double arg1)
{
    ui->newTransanction_credit->setValue(0);
}

void fen_newtransaction::on_newTransanction_credit_valueChanged(double arg1)
{
    ui->newTransanction_debit->setValue(0);
}
