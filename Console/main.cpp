#include <iostream>
#include <string>
#include <sstream>
#include "CompteManager.h"
#include "TransactionManager.h"
#include "Operation.h"


using namespace std;

  void clear_screen()
 
  {
 
  #ifdef WINDOWS
 
  std::system ( "CLS" );
 
  #else
 
  // Assume POSIX
 
  std::system ( "clear" );
 
  #endif
 
  }

int main()
{
    TransactionManager& tm = TransactionManager::getInstance();
    CompteManager& c=CompteManager::getInstance();
    
    
    c.creerCompte(c.getRacine(),"TEST SUPPRESSION",actif,virtuel);
		c.creerCompte(c.getRacine(),"Actifs",actif,virtuel);
		c.creerCompte(c.getRacine(),"Passifs",passif,virtuel);
		c.creerCompte(c.getRacine(),"Depenses",depense,virtuel);
		c.creerCompte(c.getRacine(),"Recettes",recette,virtuel);
		
		c.creerCompte(c.getCompteByNom("Actifs"),"Big Bank",actif,virtuel);
		c.creerCompte(c.getCompteByNom("Actifs"),"Caisse",actif,168.30,reel);
		c.creerCompte(c.getCompteByNom("Actifs"),"Cheques a encaisser",actif,1256.87,reel);

		c.creerCompte(c.getCompteByNom("Big Bank"),"Compte cheque",actif,70,reel);
		c.creerCompte(c.getCompteByNom("Big Bank"),"Livret A",actif,3597.70,reel);

		c.creerCompte(c.getCompteByNom("Passifs"),"Emprunt",passif,1200,reel);


		c.creerCompte(c.getCompteByNom("Depenses"),"Assurance",depense,0,reel);
		c.creerCompte(c.getCompteByNom("Depenses"),"Frais",depense,virtuel);
		c.creerCompte(c.getCompteByNom("Frais"),"Frais de personnel",depense,0,reel);
		c.creerCompte(c.getCompteByNom("Frais"),"Materiel",depense,reel);

		c.creerCompte(c.getCompteByNom("Recettes"),"Cotisations",recette,0,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Dons",recette,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Interets d'epargne",recette,0,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Subventions",recette,reel);
    
    Operation* op1 = new Operation(60, 0, dynamic_cast<CompteReel&> (c.getCompteByNom("Compte cheque")));
   Operation* op2 = new Operation(0,40, dynamic_cast<CompteReel&> (c.getCompteByNom("Cotisations")));
   Operation* op5 = new Operation(0,20, dynamic_cast<CompteReel&> (c.getCompteByNom("Dons")));

    vector<Operation*> vec;

    vec.push_back(op1);
    vec.push_back(op2);
    vec.push_back(op5);


    const TIME::Date d;


    tm.ajouterTransaction(d ,1, "memo1",vec);

    Operation* op3 = new Operation(10, 0, dynamic_cast<CompteReel&> (c.getCompteByNom("Livret A")));
    Operation* op4 = new Operation(0,10, dynamic_cast<CompteReel&> (c.getCompteByNom("Subventions")));

    vector<Operation*> vec2;

    vec2.push_back(op3);
    vec2.push_back(op4);


    tm.ajouterTransaction(d ,5, "memo2",vec2);
    
     Operation* opbis = new Operation(500, 0, dynamic_cast<CompteReel&> (c.getCompteByNom("Livret A")));
    Operation* opbis2 = new Operation(0,500, dynamic_cast<CompteReel&> (c.getCompteByNom("Cotisations")));

    vector<Operation*> vec3;

    vec3.push_back(opbis);
    vec3.push_back(opbis2);


    tm.ajouterTransaction(d ,6, "memo3",vec3);
    
   bool continuer=true;
   int choix, choix_compte, choix_transaction;
   stringstream nom, nom_pere;
   string input;
   int type,r;
   int type_compte;
   double solde_init;
   Compte& compte = c.getRacine();
   Compte& compte_pere = c.getRacine();
    
    clear_screen();
    do{
    	
   	cout<<"┌─────────────────────────────────┐\n";
	cout<<"│    GESTIONNAIRE DE TRESORERIE   │\n";
	cout<<"└─────────────────────────────────┘\n";
    
    	
    	cout<<"\tMENU:\n";
    	
    	cout<<"\t\t1. Gestionnaire des comptes\n";
    	cout<<"\t\t2. Gestionnaire des transactions\n";
    	cout<<"\t\t3. Cloturer le livre\n";
    	cout<<"\t\t4. Rapprocher un compte\n";
    	cout<<"\t\t5. Quitter\n\n";
    	
    	cout<<"\tVotre choix: ";
    	cin>>choix;
    	
    	
    	switch (choix)
    	{
    		case 1:
    			clear_screen();
    			cout<<"┌───────────────────────────────┐\n";
			cout<<"│    Gestionnaire des comptes   │\n";
			cout<<"└───────────────────────────────┘\n\n\n";
    			c.afficher();
    			cout<<"\n\n";
    			
    			cout<<"\tMENU:\n";
    	
    			cout<<"\t\t1. Créer un compte\n";
    			cout<<"\t\t2. Supprimer un compte\n";
    			cout<<"\t\t3. Modifier un compte\n";
    			cout<<"\t\t4. Déplacer un compte\n";
    			cout<<"\t\t5. Quitter\n\n";
    	
    			cout<<"\tVotre choix: ";
    			cin>>choix_compte;
    			
    			switch(choix_compte)
    			{
    				case 1:
    					try {
    				
    						cout<<"\tQuel est le nom de votre compte : ";
    						nom.str("");
    						cin.ignore(256, '\n');
						getline(cin,input);
    						nom.str(input);
    						
    						cout<<"\tQuel est le type de votre compte (0:actif,1:passif,2:depense,3:recette) : ";
    						cin>>type;
    						if(type<0  || type>3) throw Erreur("\nERREUR: Mauvais type entré\n");
    						cout<<"\tVotre compte est-il réel (0: non, 1:oui) : ";
    						cin>>type_compte;
    						if(type_compte<0  || type_compte>1) throw Erreur("\nERREUR: Mauvais type compte entré\n");
    						cout<<"\tQuel est le solde initial de votre compte : ";
    						cin>>solde_init;
    						cout<<"\tQuel est le nom du père de votre compte : ";
    						nom_pere.str("");
    						cin.ignore(256, '\n');
						getline(cin,input);
    						nom_pere.str(input);
    						
    						//compte_pere=c.getCompteByNom(nom_pere.str());
    			
    						c.creerCompte(c.getCompteByNom(nom_pere.str()),nom.str(),static_cast<Type>(type),solde_init,static_cast<TypeCompte>(type_compte));
    					
    						clear_screen();
    						cout<<"Nouveau compte bien créé.\n\n";
    					
    					}
    					catch(const Erreur& e)
					{
						clear_screen();
						cerr<<e.what()<<"\n\n";
					}
    				break;
    				case 2:
    					try {
    						cout<<"\tQuel est le nom du compte à supprimer : ";
    						nom.str("");
    						cin.ignore(256, '\n');
						getline(cin,input);
    						nom.str(input);
    						
    						c.supprimerCompte(c.getCompteByNom(nom.str()));
    						
    						clear_screen();
    						cout<<"Compte supprimé avec succès.\n\n";
    					}
    					catch(const Erreur& e)
					{
						clear_screen();
						cerr<<e.what()<<"\n\n";
					}
    				break;
    				case 3:
    					try {
    						cout<<"\tQuel est le nom du compte à éditer : ";
    						nom.str("");
    						cin.ignore(256, '\n');
						getline(cin,input);
    						nom.str(input);
    						
    						cout<<"\tQuel nouveau nom voulez-vous donner à votre compte : ";
    						
    						cin>>input;
    						
    						c.editerCompte(c.getCompteByNom(nom.str()),input);
    						
    						clear_screen();
    						cout<<"Compte édité avec succès.\n\n";
    					}
    					catch(const Erreur& e)
					{
						clear_screen();
						cerr<<e.what()<<"\n\n";
					}
    				break;
    				case 4:
    					try {
    						cout<<"\tQuel est le nom du compte à déplacer : ";
    						nom.str("");
    						cin.ignore(256, '\n');
						getline(cin,input);
    						nom.str(input);
    						
    						cout<<"\tQuel est le nom du nouveau père : ";
    						cin>>input;
    						
    						c.deplacerCompte(c.getCompteByNom(input),c.getCompteByNom(nom.str()));
    						
    						clear_screen();
    						cout<<"Compte déplacé avec succès.\n\n";
    					}
    					catch(const Erreur& e)
					{
						clear_screen();
						cerr<<e.what()<<"\n\n";
					}
    					
    				break;
    				default:
    					clear_screen();
    				break;
    			}
    		break;
    		case 2:
    			clear_screen();
    			cout<<"┌────────────────────────────────────┐\n";
			cout<<"│    Gestionnaire des transactions   │\n";
			cout<<"└────────────────────────────────────┘\n\n\n";
    			cout<<"\n\n";
    			
    			cout<<"\tMENU:\n";
    	
    			cout<<"\t\t1. Afficher toutes les transactions\n";
    			cout<<"\t\t2. Afficher toutes les transactions d'un compte\n";
    			cout<<"\t\t3. Supprimer une transaction\n";
    			cout<<"\t\t4. Quitter\n\n";
    	
    			cout<<"\tVotre choix: ";
    			cin>>choix_transaction;
    			
    			switch(choix_transaction)
    			{
    				case 1:
    					try {
    						cout<<"┌───────────────────────────────────────┐\n";
						cout<<"│    LISTES DE TOUTES LES TRANSACTION   │\n";
						cout<<"└───────────────────────────────────────┘\n\n\n";
    						tm.afficherTransactions();
    					
    					}
    					catch(const Erreur& e)
					{
						clear_screen();
						cerr<<e.what()<<"\n\n";
					}
    				break;
    				case 2:
    					try {
    						cout<<"\tQuel est le nom du compte don't vous voulez voir les transactions : ";
    						nom.str("");
    						cin.ignore(256, '\n');
						getline(cin,input);
    						nom.str(input);
    						
    						tm.afficherTransactionsCompte(static_cast<CompteReel&>(c.getCompteByNom(nom.str())));
    						
    					}
    					catch(const Erreur& e)
					{
						clear_screen();
						cerr<<e.what()<<"\n\n";
					}
    				break;
    				case 3:
    					try {
    						cout<<"\tQuel est la référence de la transaction à supprimer? : ";
    						cin>>r;
    						
    						tm.supprimerTransaction(r);
    						
    						clear_screen();
    						cout<<"\n\n\tTransaction supprimée avec succès";
 
    					}
    					catch(const Erreur& e)
					{
						clear_screen();
						cerr<<e.what()<<"\n\n";
					}
    				break;
    				case 4:
    					
    					
    				break;
    				default:
    					clear_screen();
    				break;
    			}
    		break;
    		case 3:
    			try{
    				c.cloturer();
    			}
    			catch(const Erreur& e)
			{
				cerr<<e.what();
			}
    		break;
    		case 4:
    			try{
    			cout<<"\tQuel est le nom du compte à rapprocher : ";
    						nom.str("");
    						cin.ignore(256, '\n');
						getline(cin,input);
    						nom.str(input);
    			
    				c.rapprocher(dynamic_cast<CompteReel&>(c.getCompteByNom(input)));
    			}
    			catch(const Erreur& e)
			{
				cerr<<e.what();
			}
    		break;
    		default:
    			continuer=false;
    		break;
    	}
    	
    
    } while(continuer);
    
    
    /*

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
		c.creerCompte(c.getCompteByNom("Actifs"),"Cheques a encaisser",actif,1256.87,reel);

		c.creerCompte(c.getCompteByNom("Big Bank"),"Compte cheque",actif,70,reel);
		c.creerCompte(c.getCompteByNom("Big Bank"),"Livret A",actif,3597.70,reel);

		c.creerCompte(c.getCompteByNom("Passifs"),"Emprunt",passif,1200,reel);


		c.creerCompte(c.getCompteByNom("Depenses"),"Assurance",depense,0,reel);
		c.creerCompte(c.getCompteByNom("Depenses"),"Frais",depense,virtuel);
		c.creerCompte(c.getCompteByNom("Frais"),"Frais de personnel",depense,0,reel);
		c.creerCompte(c.getCompteByNom("Frais"),"Materiel",depense,reel);

		c.creerCompte(c.getCompteByNom("Recettes"),"Cotisations",recette,0,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Dons",recette,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Interets d'epargne",recette,0,reel);
		c.creerCompte(c.getCompteByNom("Recettes"),"Subventions",recette,reel);


		
	//Test deplacer
		c.deplacerCompte(c.getRacine(),c.getCompteByNom("Emprunt"));
		

	//Test d'affichage console
		//c.afficher();

		Operation* op1 = new Operation(60, 0, dynamic_cast<CompteReel&> (c.getCompteByNom("Compte cheque")));
   Operation* op2 = new Operation(0,40, dynamic_cast<CompteReel&> (c.getCompteByNom("Cotisations")));
   Operation* op5 = new Operation(0,20, dynamic_cast<CompteReel&> (c.getCompteByNom("Dons")));

    vector<Operation*> vec;

    vec.push_back(op1);
    vec.push_back(op2);
    vec.push_back(op5);


    const TIME::Date d;


    tm.ajouterTransaction(d ,1, "memo1",vec);
    c.afficher();
    Operation* op3 = new Operation(10, 0, dynamic_cast<CompteReel&> (c.getCompteByNom("Livret A")));
    Operation* op4 = new Operation(0,10, dynamic_cast<CompteReel&> (c.getCompteByNom("Subventions")));

    vector<Operation*> vec2;

    vec2.push_back(op3);
    vec2.push_back(op4);


    tm.ajouterTransaction(d ,5, "memo2",vec2);
    
    c.cloturer();
	c.rapprocher(dynamic_cast<CompteReel&> (c.getCompteByNom("Cotisations")));


tm.afficherTransactions();

	c.afficher();*/


	


}
