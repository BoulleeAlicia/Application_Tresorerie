/***********************************************************************************
	@file CompteReel.cpp
	@brief Définition de la classe CompteReel
	@version v2
	@date 9 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include <sstream>
#include "CompteReel.h"

using namespace std;

double CompteReel::getSolde() const{return solde;}

void CompteReel::crediter(double m) {
    if (m < 0)
        throw Erreur("Operation impossible car le montant est inferieur a 0");
    else{
        if (getType()==passif || getType()==recette)solde+=m;
        if (getType()==actif || getType()==depense)solde-=m;
    }
}

void CompteReel::debiter (double m) {
    if (m < 0 )
        throw Erreur("Operation impossible car le montant est inferieur a 0");
    else{
        if (getType()==passif || getType()==recette)solde-=m;
        if (getType()==actif || getType()==depense)solde+=m;
    }
}

TypeCompte CompteReel::getTypeCompte() const
{
	return reel;
}


string CompteReel::toString() const
{
	stringstream s;

	s<<"[REEL]";

	if (type==actif) s<<" A- ";
	else if (type==passif) s<<" P- ";
	else if (type==depense) s<<" D- ";
	else if (type==recette) s<<" R- ";

	s<<getNom()<<" :"<<getSolde()<<"€\n";

	return s.str();
}

void CompteReel::afficher(int profondeur) const
{
	for(unsigned int i=0;i<profondeur;i++) cout<<"	";
	cout<<toString();
}

bool CompteReel::existeNom(const string& n) const
{
	if(getNom()==n) return true;
	else return false;
}

