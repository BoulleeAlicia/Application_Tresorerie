#include "fen_newcompte.h"
#include "ui_fen_newcompte.h"
#include "mainwindow.h"

fen_newcompte::fen_newcompte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_newcompte)
{
    ui->setupUi(this);
    CompteManager& c = CompteManager::getInstance();
    CompteRacine& r = c.getRacine();
    vector<Compte*> fils = r.getFils();
    QString::fromStdString(r.getNom());
    ui->box_compteParent->addItem(QString::fromStdString(r.getNom()));
    afficher_comptes(fils);

}

fen_newcompte::~fen_newcompte()
{
    delete ui;
}




void fen_newcompte::on_box_compteParent_currentIndexChanged(const QString &arg1)
{
    CompteManager& c = CompteManager::getInstance();
    Compte& compte = c.getCompteByNom(arg1.toStdString());

    if(compte.getType()==actif){
        ui->Type_Compte->setCurrentIndex(actif);
        ui->Type_Compte->setEnabled(false);
    }
    else if(compte.getType()==passif){
        ui->Type_Compte->setCurrentIndex(passif);
        ui->Type_Compte->setEnabled(false);
    }
    else if(compte.getType()==depense){
        ui->Type_Compte->setCurrentIndex(depense);
        ui->Type_Compte->setEnabled(false);
    }
    else if(compte.getType()==recette){
        ui->Type_Compte->setCurrentIndex(recette);
        ui->Type_Compte->setEnabled(false);
    }
    else{
        ui->Type_Compte->setEnabled(true);
    }
}



void fen_newcompte::on_newCompte_OK_accepted()
{
    accept();
}

void fen_newcompte::on_newCompte_OK_rejected()
{
    reject();
}

QString fen_newcompte::getCompte_parent() const{
    return ui->box_compteParent->itemText(ui->box_compteParent->currentIndex());
}
QString fen_newcompte::getType_compte() const{
    return ui->Type_Compte->itemText(ui->Type_Compte->currentIndex());
}
QString fen_newcompte::getNom_compte() const{
    return ui->newCompte_nom->text();
}
QString fen_newcompte::getVirtuel() const{
    return ui->newCompte_virtuel->itemText(ui->newCompte_virtuel->currentIndex());
}
double fen_newcompte::getSolde() const{
    return ui->newCompte_solde->value();
}


void fen_newcompte::afficher_comptes(vector<Compte*> f){
    if(f.size()==0) return;
    CompteVirtuel* v;
    QString nom;
    for(std::vector<Compte*>::iterator it=f.begin();it!=f.end();it++){
        if((*it)->getTypeCompte() == virtuel){
            v = dynamic_cast<CompteVirtuel*>((*it));
            afficher_comptes(v->getFils());
            nom = QString::fromStdString(v->getNom());
            ui->box_compteParent->addItem(nom);
        }
    }
}
