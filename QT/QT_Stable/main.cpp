#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "TransactionManager.h"
#include "CompteManager.h"
#include "Operation.h"

int main(int argc, char *argv[])
{
    CompteManager& c=CompteManager::getInstance();
    c.creerCompte(c.getRacine(),"Actifs",actif,0);
            c.creerCompte(c.getRacine(),"Passifs",passif,0);
            c.creerCompte(c.getRacine(),"Depenses",depense,0);
            c.creerCompte(c.getRacine(),"Recettes",recette,0);
            c.creerCompte(c.getRacine(),"Capitaux propres",passif,4000);
            c.creerCompte(c.getCompteByNom("Actifs"),"Big Bank",actif,0);
            c.creerCompte(c.getCompteByNom("Actifs"),"Caisse",actif,300);
            c.creerCompte(c.getCompteByNom("Actifs"),"Chèques à encaisser",actif,450);

            c.creerCompte(c.getCompteByNom("Big Bank"),"Compte chèque",actif,100);
            c.creerCompte(c.getCompteByNom("Big Bank"),"Livret A",actif,200);

            c.creerCompte(c.getCompteByNom("Passifs"),"Emprunt",passif,300);


            c.creerCompte(c.getCompteByNom("Depenses"),"Assurance",depense,600);
            c.creerCompte(c.getCompteByNom("Depenses"),"Frais",depense,0);
            c.creerCompte(c.getCompteByNom("Depenses"),"Frais de personnel",depense,500);
            c.creerCompte(c.getCompteByNom("Depenses"),"Matériel",depense,200);

            c.creerCompte(c.getCompteByNom("Recettes"),"Cotisations",recette,300);
            c.creerCompte(c.getCompteByNom("Recettes"),"Dons",recette,3000);
            c.creerCompte(c.getCompteByNom("Recettes"),"Intérêts d'épargne",recette,20);
            c.creerCompte(c.getCompteByNom("Recettes"),"Subventions",recette,3000);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
