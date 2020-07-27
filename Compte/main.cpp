#include <iostream>
#include "CompteManager.h"
#include "TransactionManager.h"
#include "Operation.h"


using namespace std;

int main()
{
    TransactionManager& tm = TransactionManager::getInstance();
    CompteManager& c=CompteManager::getInstance();

    try{
	//Création du compte manager


	//Création des divers comptes
		c.creerCompte(c.getRacine(),"TEST SUPPRESSION",actif,virtuel);
		c.creerCompte(c.getRacine(),"Actifs",actif,virtuel);
		c.creerCompte(c.getRacine(),"Passifs",passif,virtuel);
		c.creerCompte(c.getRacine(),"Depenses",depense,virtuel);
		c.creerCompte(c.getRacine(),"Recettes",recette,virtuel);
		
		c.creerCompte(c.getCompteByNom("Actifs"),"Big Bank",actif,virtuel);
		c.creerCompte(c.getCompteByNom("Actifs"),"Caisse",actif,168.30,reel);
		c.creerCompte(c.getCompteByNom("Actifs"),"Chèques à encaisser",actif,1256.87,reel);

		c.creerCompte(c.getCompteByNom("Big Bank"),"Compte chèque",actif,70,reel);
		c.creerCompte(c.getCompteByNom("Big Bank"),"Livret A",actif,3597.70,reel);

		c.creerCompte(c.getCompteByNom("Passifs"),"Emprunt",passif,1200,reel);


		c.creerCompte(c.getCompteByNom("Depenses"),"Assurance",depense,0,reel);
		c.creerCompte(c.getCompteByNom("Depenses"),"Frais",depense,virtuel);
		c.creerCompte(c.getCompteByNom("Frais"),"Frais de personnel",depense,0,reel);
		c.creerCompte(c.getCompteByNom("Frais"),"Matériel",depense,reel);

		c.creerCompte(c.getCompteByNom("Recettes"),"Cotisations",recette,0,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Dons",recette,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Intérêts d'épargne",recette,0,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Subventions",recette,reel);

	//Test de suppression
		c.supprimerCompte(c.getCompteByNom("TEST SUPPRESSION"));
		
	//Test deplacer
		//c.deplacerCompte(c.getRacine(),c.getCompteByNom("Emprunt"));
		

	//Test d'affichage console
		c.afficher();

		Operation* op1 = new Operation(60, 0, dynamic_cast<CompteReel&> (c.getCompteByNom("Compte chèque")));
    Operation* op2 = new Operation(0,60, dynamic_cast<CompteReel&> (c.getCompteByNom("Cotisations")));

    vector<Operation*> vec;

    vec.push_back(op1);
    vec.push_back(op2);


    const TIME::Date d;


    tm.ajouterTransaction(d ,1, "memo1",vec);
    
    Operation* op3 = new Operation(10, 0, dynamic_cast<CompteReel&> (c.getCompteByNom("Livret A")));
    Operation* op4 = new Operation(0,10, dynamic_cast<CompteReel&> (c.getCompteByNom("Subventions")));

    vector<Operation*> vec2;

    vec2.push_back(op3);
    vec2.push_back(op4);


    tm.ajouterTransaction(d ,5, "memo2",vec2);
    
    c.afficher();

    c.cloturer();
    c.afficher();
	
	c.rapprocher(dynamic_cast<CompteReel&> (c.getCompteByNom("Cotisations")));

tm.afficherTransactions();

	 c.afficher();

	
    	}
	catch(const Erreur& e)
	{
		cerr<<e.what();
	}


}