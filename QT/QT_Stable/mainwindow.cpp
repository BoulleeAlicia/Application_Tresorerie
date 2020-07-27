#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fen_newcompte.h"
#include "fen_touslescomptes.h"
#include "fen_releves.h"
#include "fen_cloture.h"
#include "fen_newtransaction.h"
#include "fen_supprimercompte.h"
#include "fen_supprimertransaction.h"
#include "fen_modifiertransaction.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CompteManager& c=CompteManager::getInstance();
    QStringList titulos;
    titulos << "Memo";
    titulos << "Reference";
    titulos << "Date";
    titulos << "Marque";
    setWindowTitle("Comptes");
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);//colocar titulos
    QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
    CompteRacine& r = c.getRacine();
    item->setText(0,QString::fromStdString(r.getNom()));
    ui->treeWidget->addTopLevelItem(item);
    afficher_comptes_main(r.getNom());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Tous_les_transactions_clicked()
{

    fen_touslesComptes fen(this);
    fen.exec();
    fen.setWindowTitle("Tous les comptes");


}

void MainWindow::on_Releves_banque_clicked()
{
    fen_releves fen(this);
    fen.exec();
    fen.setWindowTitle("Tous les comptes");
}

void MainWindow::on_Cloture_clicked()
{
    fen_cloture fen(this);
    fen.exec();
    fen.setWindowTitle("Tous les comptes");
}

void MainWindow::on_Ajouter_compte_clicked()
{
    int res;
    QString parent;
    QString type;
    QString nom;
    QString virt;
    double solde;

    fen_newcompte fen(this);
    fen.setWindowTitle("New Compte");
    res = fen.exec();

    if(res == QDialog::Rejected){
        return;
    }
    else{
        parent = fen.getCompte_parent();
        type = fen.getType_compte();
        nom = fen.getNom_compte();
        virt = fen.getVirtuel();
        solde = fen.getSolde();

        //Ajouter Compte realment
        CompteManager& c=CompteManager::getInstance();
        Type t;
        if(type.toStdString()=="Actif") t=actif;
        if(type.toStdString()=="Passif") t=passif;
        if(type.toStdString()=="Depense") t=depense;
        if(type.toStdString()=="Recette") t=recette;
        c.creerCompte(c.getCompteByNom(parent.toStdString()),nom.toStdString(),t,solde);
        //

        //Falta confimar los elementos
        QList<QTreeWidgetItem*> clist = ui->treeWidget->findItems(parent, Qt::MatchExactly|Qt::MatchRecursive, 0);
        qDebug()<<clist.count();
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0,nom);
        item->setText(1,QString::number(solde));
        item->setText(2,parent);
        item->setText(3,virt);
        item->setText(4,type);
        clist[0]->addChild(item);
    }

}

void MainWindow::afficher_comptes_main(string n){
    CompteManager& c=CompteManager::getInstance();
    vector<Compte*> f;
    if(c.getRacine().getNom()==n){f = (dynamic_cast<CompteVirtuel&>(c.getRacine())).getFils();}
    else {f = (dynamic_cast<CompteVirtuel&>(c.getCompteByNom(n))).getFils();}
    if(f.size()==0) return;
    QString nom;
    QString solde;
    QString parent = QString::fromStdString(c.getCompteByNom(n).getNom());
    QString virt = QString::fromStdString("caca");
    QString type;
    QString date;

    QTreeWidgetItem *item = new QTreeWidgetItem();
    QList<QTreeWidgetItem*> clist;
    if(c.getRacine().getNom()==n) {clist = ui->treeWidget->findItems(QString::fromStdString(c.getRacine().getNom()), Qt::MatchExactly|Qt::MatchRecursive, 0);}
    else {clist = ui->treeWidget->findItems(QString::fromStdString(c.getCompteByNom(n).getNom()), Qt::MatchExactly|Qt::MatchRecursive, 0);}
    for(std::vector<Compte*>::iterator it=f.begin();it!=f.end();it++){
        nom = QString::fromStdString((*it)->getNom());
        solde = QString::number((*it)->getSolde());
        //virtual
        if((*it)->getType() == actif) type = QString::fromStdString("Actif");
        if((*it)->getType() == passif) type = QString::fromStdString("Passif");
        if((*it)->getType() == depense) type = QString::fromStdString("Depense");
        if((*it)->getType() == recette) type = QString::fromStdString("Recette");
        item->setText(0,nom);
        item->setText(1,solde);
        item->setText(2,parent);
        item->setText(3,virt);
        item->setText(4,type);

        clist[0]->addChild(item);
        item=new QTreeWidgetItem();
    }
    for(std::vector<Compte*>::iterator it=f.begin();it!=f.end();it++){
        if((*it)->getTypeCompte() == virtuel){
            string m = (*it)->getNom();
            afficher_comptes_main(m);
        }
    }
}

void MainWindow::on_Ajouter_transaction_clicked()
{
    int res;
    QString memo;
    int reference;
    QDate date;

    fen_newtransaction fen(this);
    fen.setWindowTitle("New Transaction");
    res = fen.exec();

    if(res == QDialog::Rejected){
        return;
    }
    else{
        vector<Operation*> vec = fen.getOperations();
        memo = fen.getMemo();
        reference = fen.getReference();
        date = fen.getDate();

        //Ajouter transaction realment
        TransactionManager& tm = TransactionManager::getInstance();


        tm.ajouterTransaction(date,reference,memo.toStdString(),false,vec);

        ui->tableWidget->clear();
        QStringList titulos;
        titulos << "Memo";
        titulos << "Reference";
        titulos << "Date";
        titulos << "Marque";
        setWindowTitle("Comptes");
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(titulos);//colocar titulos
        tm.afficherTransactionsQT(ui->tableWidget);

    }
}

void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    int res;
    fen_Supprimercompte fen(this);
    fen.setWindowTitle("Supprimer Compte");
    res = fen.exec();
    int solde ;
    QString nom ;
    CompteManager& c=CompteManager::getInstance();
    QList<QTreeWidgetItem*> item_list = ui->treeWidget->selectedItems();
    QTreeWidgetItem* selectedItem = item_list.at(0);
        if(!item_list.empty()){
            nom = selectedItem->text(0);
        }
    solde = c.getCompteByNom(nom.toStdString()).getSolde();

    if(res == QDialog::Rejected){
        return;
    }
    else{
        //CompteManager& c=CompteManager::getInstance();

        QList<QTreeWidgetItem*> item_list = ui->treeWidget->selectedItems();
        QTreeWidgetItem* selectedItem = item_list.at(0);
            if(!item_list.empty()){
                QString nom = selectedItem->text(0);
                c.supprimerCompte(c.getCompteByNom(nom.toStdString()));

                ui->treeWidget->clear();
                QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
                CompteRacine& r = c.getRacine();
                item->setText(0,QString::fromStdString(r.getNom()));
                ui->treeWidget->addTopLevelItem(item);
                afficher_comptes_main(r.getNom());
            }
    }
}

void MainWindow::on_Supprimer_clicked()
{
    int res;
    int r;
    TransactionManager& tm = TransactionManager::getInstance();

    fen_supprimertransaction fen(this);
    fen.setWindowTitle("New Transaction");
    res = fen.exec();

    if(res == QDialog::Rejected){
        return;
    }
    else{
        r = fen.getReference();
        tm.supprimerTransaction(r);
        ui->tableWidget->clear();
        QStringList titulos;
        titulos << "Memo";
        titulos << "Reference";
        titulos << "Date";
        titulos << "Marque";
        setWindowTitle("Comptes");
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(titulos);//colocar titulos
        tm.afficherTransactionsQT(ui->tableWidget);

    }
}

void MainWindow::on_Modifier_transaction_clicked()
{
    int res;
    QString memo;
    QDate date;
    int reference;
    TransactionManager& tm = TransactionManager::getInstance();

    fen_modifiertransaction fen(this);
    fen.setWindowTitle("Modifier Transaction");
    res = fen.exec();

    if(res == QDialog::Rejected){
        return;
    }
    else {
        memo = fen.getMemo();
        date = fen.getDate();
        reference = fen.getReference();
        Transaction* tr;
        tr = tm.getTransaction(reference);
        tr->setDate(date);
        tr->setMemo(memo.QString::toStdString());
        vector<Operation*> old_op = tr->getOperation() ;
        if ( !(fen.getOperations().empty()) ){
            tr->setOperation(fen.getOperations());
            tr->Validation_Vector_Operations(fen.getOperations());
        }
    }


}
