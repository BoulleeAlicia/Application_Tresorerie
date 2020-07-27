#include <iostream>
#include <vector>
#include <list>
#include "CompteManager.h"

/***********************************************************************************
	@file CompteManager.cpp
	@brief CompteManager permet de gérer l'emsemble des comptes.
	@version v2
	@date 9 juin 2020
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

void CompteManager::creerCompte(Compte& p, const string& n, Type t, double s)
{
	if (existeNom(n)) throw Erreur("ERREUR: Nom de compte déjà existant");
	if (p.getTypeCompte()==virtuel) // Si le compte est virtuel, on le place direct dans ses fils
	{
		CompteReel *new_compte= new CompteReel(n,t,s);
		static_cast<CompteVirtuel&>(p).creerFils(new_compte);
	}
	else if (p.getTypeCompte()==reel) // Sinon, si il est virtualisable, on le virtualise et le place dans ses fils
	{
		if (p.getSolde() != 0) throw Erreur("ERREUR: Impossible de virtualiser le compte père (solde non nul)");
		if (p.getType()!=t) throw Erreur("ERREUR: Impossible le compte fils doit être du même type que le compte père");
	
		CompteReel *new_compte= new CompteReel(n,t,s);
		CompteVirtuel *comptev= new CompteVirtuel(p.getNom(),p.getType());
		comptev->creerFils(new_compte);
		static_cast<CompteVirtuel&>(getPere(p)).creerFils(comptev);
		supprimerCompte(p);
	}
	
}

void CompteManager::supprimerCompte(Compte& c)
{
	if (c.getType()==racine) throw Erreur("ERREUR: Impossible de supprimer la racine"); // On essaye de supprimer la racine
	static_cast<CompteVirtuel&>(getPere(c)).supprimerFils(c);
}

void CompteManager::afficher() const
{
	getRacine().afficher(0); // On affiche la hiérarchie des comptes depuis la racine
}

bool CompteManager::existeNom(const string& n) const
{
	return getRacine().existeNom(n); // On teste l'existence du nom depuis la racine
}

Compte& CompteManager::getCompteByNom(const string& n)
{
	if (existeNom(n))
		return getRacine().getCompteByNom(n);
	else throw Erreur("ERREUR: Le compte n'existe pas");
}

Compte& CompteManager::getPere(const Compte& c)
{
	return getRacine().getPere(c);
}
