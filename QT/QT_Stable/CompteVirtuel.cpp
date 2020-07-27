/***********************************************************************************
	@file Comptevirtuel.cpp
	@brief Définition de la classe CompteVirtuel
	@version v2
	@date 9 juin 2020
	@bug aucun détecté
   	@warning COMPILE
	@note
***********************************************************************************/

#include <sstream>
#include <vector>
#include "CompteVirtuel.h"

using namespace std;


void CompteVirtuel::creerFils(Compte* c){
    fils.push_back(c);
}

void CompteVirtuel::supprimerFils (Compte& c){
	for(vector<Compte*>::iterator it = fils.begin(); it!=fils.end(); ++it)
    	{
    		if ((*it)==&c)
    		{
    			fils.erase(it);
    			return;
    		}
    	}
}

double CompteVirtuel::getSolde() const {
    double solde=0;
    for (auto c : fils) {
        solde += c->getSolde();
    }
    return solde;
}


TypeCompte CompteVirtuel::getTypeCompte() const
{
	return virtuel;
}

string CompteVirtuel::toString() const
{
	stringstream s;
	
	s<<"[VIRTUEL]";
	
	if (type==actif) s<<" A- ";
	else if (type==passif) s<<" P- ";
	else if (type==depense) s<<" D- ";
	else if (type==recette) s<<" R- ";
	else if (type==racine) s<<" ";
	
	return s.str();
}

void CompteVirtuel::afficher(int profondeur) const
{
	for(unsigned int i=0;i<profondeur;i++) cout<<"	";
	cout<<toString()<<getNom()<<" - Solde: "<<getSolde()<<"€\n";
	
	for (auto& j : fils)
	{
		j->afficher(profondeur+1);
        	
	}
}

Compte& CompteVirtuel::getCompteByNom(const string& n)
{
	if(getNom()==n) return *this;
	
	for (auto j=fils.begin();j!=fils.end();j++)
	{
		if ((*j)->getTypeCompte()==reel) 
			if ((*j)->getNom()==n) return *(*j);
		if ((*j)->getTypeCompte()==virtuel)
		{
			if (dynamic_cast<CompteVirtuel*>(*j)->existeNom(n)!=0) return dynamic_cast<CompteVirtuel*>(*j)->getCompteByNom(n);
		}
	}
}

bool CompteVirtuel::existeNom(const string& n) const
{
	int flag=0;
	if(getNom()==n) return true;
	
	for (auto j=fils.begin();j!=fils.end();j++)
	{
		if((*j)->existeNom(n)==true) return true;
	}
	return false;
}

Compte& CompteVirtuel::getPere(const Compte& c)
{
	for (auto& j : getFils())
	{
		if (j==&c) return *this;
		if (j->getTypeCompte()==virtuel) return dynamic_cast<CompteVirtuel*>(j)->getPere(c);
	}
}
