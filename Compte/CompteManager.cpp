#include <iostream>
#include <vector>

#include "CompteManager.h"

/***********************************************************************************
	@file CompteManager.cpp
	@brief CompteManager permet de gérer l'emsemble des comptes.
	@version v3
	@date 17 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

using namespace std;

CompteManager CompteManager::instance=CompteManager();
CompteRacine CompteManager::rac=CompteRacine::getInstance();

CompteManager& CompteManager::getInstance()
{
    return instance;
}

Compte& CompteManager::getPere(const Compte& c)
{
	return getRacine().getPere(c);
}

void CompteManager::creerCompte(Compte& p, const string& n, Type t, double s, TypeCompte tc)
{
	try{
		if (existeNom(n)) throw Erreur("ERREUR: Nom de compte déjà existant");
		else if (p.getTypeCompte()==reel) throw Erreur("ERREUR : Impossible de créer un compte si le compte père est un compte réel");
		else if (p.getType()!=t && p.getType()!=racine) throw Erreur("ERREUR : Impossible d'ajouter un compte avec un type différent de son compte père");
		else if (s<0) throw Erreur("ERREUR : Impossible d'ajouter un compte avec un solde initial négatif");
		else if (p.getType()==racine && t!=passif && tc==reel) throw Erreur("ERREUR : Impossible d'ajouter un compte réel non passif sous la racine");
		else if (t!=passif && t!=actif && s>0) throw Erreur("ERREUR : Impossible d'initialiser le solde d'un compte de dépense ou de recette");
	
		if(tc==reel) {
			CompteReel *new_compte= new CompteReel(n,t,0);
			static_cast<CompteVirtuel&>(p).creerFils(new_compte);
		
			if (s!=0)
			{
				if (!existeNom("Capitaux propres")) creerCompte(getRacine(), "Capitaux propres", passif, reel);
				
				if (t==passif || t==recette)
				{
					dynamic_cast<CompteReel&>(*new_compte).crediter(s);
					dynamic_cast<CompteReel&>(getCompteByNom("Capitaux propres")).debiter(s);
				}
				if (t==actif || t==depense)
				{
					dynamic_cast<CompteReel&>(*new_compte).debiter(s);
					dynamic_cast<CompteReel&>(getCompteByNom("Capitaux propres")).crediter(s);
				}
			}
		}
		else if(tc==virtuel) {
			CompteVirtuel *new_compte= new CompteVirtuel(n,t);
			static_cast<CompteVirtuel&>(p).creerFils(new_compte);
		}
	}
	catch(const Erreur& e)
	{
		cerr<<e.what();
	}
}

void CompteManager::creerCompte(Compte& p, const string& n, Type t, TypeCompte tc)
{
	try{
		if (existeNom(n)) throw Erreur("ERREUR: Nom de compte déjà existant");
		else if (p.getTypeCompte()==reel) throw Erreur("ERREUR : Impossible de créer un compte si le compte père est un compte réel");
		else if (p.getType()!=t && p.getType()!=racine) throw Erreur("ERREUR : Impossible d'ajouter un compte avec un type différent de son compte père");
		else if (p.getType()==racine && t!=passif && tc==reel) throw Erreur("ERREUR : Impossible d'ajouter un compte réel non passif sous la racine");

		if(tc==reel) {
			CompteReel *new_compte= new CompteReel(n,t,0);
			static_cast<CompteVirtuel&>(p).creerFils(new_compte);
		}
		else if(tc==virtuel) {
			CompteVirtuel *new_compte= new CompteVirtuel(n,t);
			static_cast<CompteVirtuel&>(p).creerFils(new_compte);
		}
	}
	catch(const Erreur& e)
	{
		cerr<<e.what();
	}
}

void CompteManager::supprimerCompte(Compte& c)
{
	try{
		if (c.getType()==racine) throw Erreur("ERREUR: Impossible de supprimer la racine"); // On essaye de supprimer la racine
		else if (c.getTypeCompte()==reel && TransactionManager::getInstance().UsageCompte(dynamic_cast<CompteReel&>(c))) throw Erreur("ERREUR: Impossible de supprimer un compte qui a des transactions");
	
		if (c.getType()==passif || c.getType()==recette)
		{
			
					static_cast<CompteReel&>(getCompteByNom("Capitaux propres")).crediter(c.getSolde());
					static_cast<CompteReel&>(c).debiter(c.getSolde());
				
		}
		else if (c.getType()==actif || c.getType()==depense)
		{
			static_cast<CompteReel&>(getCompteByNom("Capitaux propres")).debiter(c.getSolde());
			static_cast<CompteReel&>(c).crediter(c.getSolde());
				
		}
	
		static_cast<CompteVirtuel&>(getPere(c)).supprimerFils(c);
	}
	catch(const Erreur& e)
	{
		cerr<<e.what();
	}
}

void CompteManager::afficher() const noexcept
{
	getRacine().afficher(1); // On affiche la hiérarchie des comptes depuis la racine
}

bool CompteManager::existeNom(const string& n) const noexcept
{
	return getRacine().existeNom(n); // On teste l'existence du nom depuis la racine
}

Compte& CompteManager::getCompteByNom(const string& n)
{
	try{
		if (existeNom(n))
			return getRacine().getCompteByNom(n);
		else throw Erreur("ERREUR: Le compte n'existe pas");
	}
	catch(const Erreur& e)
	{
		cerr<<e.what();
	}
}

void CompteManager::editerCompte(Compte& c, const string& n){
	try{
		if (n!=c.getNom() && existeNom(n)) throw Erreur("ERREUR: Nom de compte déjà existant");
		else if (c.getType()==racine) throw Erreur("ERREUR: Impossible d'éditer la racine");
	
		c.nom=n;
	}
	catch(const Erreur& e)
	{
		cerr<<e.what();
	}
}

void CompteManager::deplacerCompte(Compte& p, Compte& c){
	try{
		if(p.getType()!=racine && c.getType()!=p.getType()) throw Erreur("ERREUR: Impossible de déplacer un compte dans un compte de type différent");
		else if(p.getTypeCompte()==reel) throw Erreur("ERREUR: Impossible de déplacer un compte dans un compte réel");
		else if(&p==&c) throw Erreur("ERREUR: Impossible de déplacer un compte dans lui-même");
		else if(c.getTypeCompte()==virtuel && dynamic_cast<CompteVirtuel&>(c).isFils(p)) throw Erreur("ERREUR: Impossible de déplacer un compte dans l'un de ses fils");
		else if (p.getType()==racine && c.getTypeCompte()==reel && c.getType()!=passif) throw Erreur("ERREUR: Impossible de déplacer un compte réel sous la racine qui n'est pas passif");
	
		dynamic_cast<CompteVirtuel&>(getPere(c)).supprimerFils(c);
		dynamic_cast<CompteVirtuel&>(p).fils.push_back(&c);
	}
	catch(const Erreur& e)
	{
		cerr<<e.what();
	}
}

void CompteManager::cloturer()
{
    if (!existeNom("Resultat"))  creerCompte(getRacine(), "Resultat", passif, reel);
    
    vector<Operation*> o_depense;
    vector<Operation*> o_recette;

    const TIME::Date d;

	o_depense.push_back(new Operation(getRacine().cloturer(o_depense,depense),0,dynamic_cast<CompteReel&>( CompteManager::getInstance().getCompteByNom("Resultat"))));
	o_recette.push_back(new Operation(0,getRacine().cloturer(o_recette,recette),dynamic_cast<CompteReel&>( CompteManager::getInstance().getCompteByNom("Resultat"))));

	

    TransactionManager::getInstance().ajouterTransaction(d,2, "Cloture",o_depense);
    TransactionManager::getInstance().ajouterTransaction(d,3, "Cloture",o_recette);
    
    vector<Operation*> o_resultat;
    
    if (CompteManager::getInstance().getCompteByNom("Resultat").getSolde()>0)
    {
    	 if (!existeNom("Excedent"))  creerCompte(getRacine(), "Excedent", passif, reel);
    	 o_resultat.push_back(new Operation(CompteManager::getInstance().getCompteByNom("Resultat").getSolde(),0,dynamic_cast<CompteReel&>(CompteManager::getInstance().getCompteByNom("Resultat"))));
    	 o_resultat.push_back(new Operation(0,CompteManager::getInstance().getCompteByNom("Resultat").getSolde(),dynamic_cast<CompteReel&>(CompteManager::getInstance().getCompteByNom("Excedent"))));
    }
    
     else if (CompteManager::getInstance().getCompteByNom("Resultat").getSolde()<0)
    {
    	 if (!existeNom("Deficit"))  creerCompte(getRacine(), "Deficit", passif, reel);
    	 o_resultat.push_back(new Operation(0,-(CompteManager::getInstance().getCompteByNom("Resultat").getSolde()),dynamic_cast<CompteReel&>(CompteManager::getInstance().getCompteByNom("Resultat"))));
    	 o_resultat.push_back(new Operation(-(CompteManager::getInstance().getCompteByNom("Resultat").getSolde()),0,dynamic_cast<CompteReel&>(CompteManager::getInstance().getCompteByNom("Deficit"))));
    }
    
     TransactionManager::getInstance().ajouterTransaction(d,4, "Cloture",o_resultat);
}

void CompteManager::rapprocher(const CompteReel& c)
{
	vector<Transaction*> t=TransactionManager::getInstance().getTransactionsByCompte(c);
	for(std::vector<Transaction*>::iterator it=t.begin();it!=t.end();it++){
                      (*it)->marque=true;
            }
}

bool CompteManager::isRapproche(const CompteReel& c)
{
	vector<Transaction*> t=TransactionManager::getInstance().getTransactionsByCompte(c);
	for(std::vector<Transaction*>::iterator it=t.begin();it!=t.end();it++){
                      if ((*it)->getMarque()==true) return true;
            }
            
            return false;
}
