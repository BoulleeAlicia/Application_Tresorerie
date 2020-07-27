/***********************************************************************************
	@file CompteRacine.cpp
	@brief CompteRacine correspond à la racine de l'aborescence des comptes.
	@version v2
	@date 9 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include "CompteRacine.h"

using namespace std;

CompteRacine CompteRacine::instance=CompteRacine("Compte racine", racine);

CompteRacine& CompteRacine::getInstance()
{
    return instance;
}

double CompteRacine::getSolde() const {
    double solde=0;
    for (auto c : getFils()) {
    	if (c->getType()==actif||c->getType()==depense)
        	solde += c->getSolde();
        if (c->getType()==passif||c->getType()==recette)
        	solde -= c->getSolde();
    }
    return solde;
}

