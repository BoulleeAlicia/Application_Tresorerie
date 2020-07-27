#include <iostream>
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
    
    
   bool continuer=true;
   int choix;
   string nom,nom_pere;;
   int type;
   int type_compte;
   double solde_init;
    
    clear_screen();
    do{
    	
   	cout<<"┌─────────────────────────────────┐\n";
	cout<<"│    GESTIONNAIRE DE TRESORERIE   │\n";
	cout<<"└─────────────────────────────────┘\n";
    
    	
    	cout<<"\tMENU:\n";
    	
    	cout<<"\t\t1. Gestionnaire des comptes\n";
    	cout<<"\t\t2. Gestionnaire des transactions\n";
    	cout<<"\t\t3. Cloturer le livre\n";
    	cout<<"\t\t4. Faire un bilan\n";
    	cout<<"\t\t5. Faire un relevé\n";
    	cout<<"\t\t6. Faire un résultat\n";
    	cout<<"\t\t7. Quitter\n\n";
    	
    	cout<<"\tVotre choix: ";
    	cin>>choix;
    	
    	clear_screen();
    	
    	switch (choix)
    	{
    		case 1:
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
    			cin>>choix;
    			
    			switch(choix)
    			{
    				case 1:
    					try {
    						cout<<"\tQuel est le nom de votre compte :";
    						cin>>nom;
    						cout<<"\tQuel est le type de votre compte (0:actif,1:passif,2:depense,3:recette) :";
    						cin>>type;
    						if(type<0  || type>3) throw Erreur("ERREUR: Mauvais type entré");
    						cout<<"\tVotre compte est-il réel (0: non, 1:oui) :";
    						cin>>type_compte;
    						if(type_compte<0  || type_compte>1) throw Erreur("ERREUR: Mauvais type compte entré");
    						cout<<"\tQuel est le solde initial de votre compte :";
    						cin>>solde_init;
    						cout<<"\tQuel est le nom du père de votre compte :";
    						cin>>nom_pere;
    						
    						c.creerCompte(c.getCompteByNom(nom_pere),nom,static_cast<Type>(type),static_cast<TypeCompte>(type_compte));
    						
    						clear_screen();
    						cout<<"Nouveau cmopte bien créé.\n\n"
    						
    					}
    					
    					catch(exception& e){
       						 cout<<e.what()<<"\n";
   					}
    				break;
    				case 2:
    				break;
    				case 3:
    				break;
    				case 4:
    				break;
    				default:
    				break;
    			}
    		break;
    		case 2:
    			
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
    		break;
    		case 5:
    		break;
    		case 6:
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

	//Test de suppression
		c.supprimerCompte(c.getCompteByNom("TEST SUPPRESSION"));
		
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