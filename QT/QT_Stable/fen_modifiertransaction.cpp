#include "fen_modifiertransaction.h"
#include "ui_fen_modifiertransaction.h"
#include <QString>

fen_modifiertransaction::fen_modifiertransaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_modifiertransaction)
{
    ui->setupUi(this);
    TransactionManager& tm = TransactionManager::getInstance();
    QLineEdit* lineEdit = new QLineEdit;
    lineEdit->setPlaceholderText( "----" );
    ui->comboBox_3->setLineEdit( lineEdit );
    tm.afficherSurQcombobox(ui->comboBox_3);
    ui->dateEdit->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->doubleSpinBox->setEnabled(false);
    ui->doubleSpinBox_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    QStringList titre;
    titre << "Compte";
    titre << "Debit";
    titre << "Credit";
    ui->tableWidget_trans->setColumnCount(3);
    ui->tableWidget_trans->setHorizontalHeaderLabels(titre);
}

fen_modifiertransaction::~fen_modifiertransaction()
{
    delete ui;
}

void fen_modifiertransaction::on_buttonBox_accepted()
{
    accept();
}

void fen_modifiertransaction::on_buttonBox_rejected()
{
    reject();
}

void fen_modifiertransaction::on_comboBox_3_currentIndexChanged(int index)
{
    ui->dateEdit->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    TransactionManager& tm = TransactionManager::getInstance();
    Transaction* tr;
    tr = tm.getTransaction(ui->comboBox_3->itemText(ui->comboBox_3->currentIndex()).toInt());
    QDate tr_date = tr->getDate();
    ui->dateEdit->setDate(tr_date);
    ui->lineEdit->setText(QString::fromStdString(tr->getMemo()));
}

QString fen_modifiertransaction::getMemo() const{
    return ui->lineEdit->text();
}

QDate fen_modifiertransaction::getDate() const{
    return ui->dateEdit->date();
}

int fen_modifiertransaction::getReference() const{
    return  ui->comboBox_3->itemText(ui->comboBox_3->currentIndex()).toInt();
}

void fen_modifiertransaction::on_pushButton_2_clicked()
{
    ui->comboBox_2->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->doubleSpinBox->setEnabled(true);
    ui->doubleSpinBox_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    CompteManager& c = CompteManager::getInstance();
    CompteRacine& r = c.getRacine();
    vector<Compte*> fils = r.getFils();
    QString::fromStdString(r.getNom());
    afficher_comptes_source(fils);
    afficher_comptes_destination(fils);
    TransactionManager& tm = TransactionManager::getInstance();
    Transaction* tr;
    tr = tm.getTransaction(ui->comboBox_3->itemText(ui->comboBox_3->currentIndex()).toInt());
    tr->Supprimer_Vector_Operations(tr);
    ui->tableWidget_trans->clear();
}

void fen_modifiertransaction::afficher_comptes_source(vector<Compte*> f){
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
            ui->comboBox->addItem(nom);
        }
    }
}

void fen_modifiertransaction::afficher_comptes_destination(vector<Compte*> f){
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
            ui->comboBox_2->addItem(nom);
        }
    }
}

void fen_modifiertransaction::on_pushButton_clicked()
{
    QString source = ui->comboBox->itemText(ui->comboBox->currentIndex());
    QString destination = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());
    double credit = ui->doubleSpinBox_2->value();
    double debit = ui->doubleSpinBox->value();

    CompteManager& c = CompteManager::getInstance();
    Operation* op1 = new Operation(debit, credit, dynamic_cast<CompteReel&> (c.getCompteByNom(destination.toStdString())));
    Operation* op2 = new Operation(credit, debit, dynamic_cast<CompteReel&> (c.getCompteByNom(source.toStdString())));
    new_op.push_back(op1);
    new_op.push_back(op2);

    ui->tableWidget_trans->insertRow(ui->tableWidget_trans->rowCount());
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 0, new QTableWidgetItem (destination));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 1, new QTableWidgetItem (QString::number(debit)));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 2, new QTableWidgetItem (QString::number(credit)));

    ui->tableWidget_trans->insertRow(ui->tableWidget_trans->rowCount());
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 0, new QTableWidgetItem (source));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 1, new QTableWidgetItem (QString::number(credit)));
    ui->tableWidget_trans->setItem(ui->tableWidget_trans->rowCount() - 1, 2, new QTableWidgetItem (QString::number(debit)));
}

vector<Operation*> fen_modifiertransaction::getOperations(){
    return new_op;
}

