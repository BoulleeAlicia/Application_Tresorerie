#ifndef COMPTERACINE_H_INCLUDED
#define COMPTERACINE_H_INCLUDED
/***********************************************************************************
	@file CompteRacine.h
	@brief CompteRacine correspond à la racine de l'aborescence des comptes.
	@version v3
	@date 9 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include <string>

#include "CompteVirtuel.h"

using namespace std;

/**
	@class CompteRacine "CompteRacine.h"
	@brief CompteRacine correspond à la racine de l'aborescence des comptes.
*/
class CompteRacine: public CompteVirtuel {
friend class CompteManager;

public :
	/**
		@fn  CompteRacine& CompteRacine::getInstance()
		@brief Méthode implémentant le design pattern Singleton.
		@return Une référence sur l'unique instance du CompteRacine.
	*/
	static CompteRacine& getInstance();
	
	/**
		@fn  double CompteRacine::getSolde() const;
		@brief Méthode calculant le solde du compte racine à partir des soldes des comptes de recettes, depenses, actifs et passifs
		@return Un double qui est le solde du compte racine.
	*/
	double getSolde() const;

private:

	    /**
        	@var static CompteRacine CompteRacine::instance
        	@brief Correspond à l'unique instance du compte racine (pour design pattern Singleton).
    	*/
    	static CompteRacine instance;
    	
    	/**
        	@var CompteRacine::CompteRacine(const string& n, Type t)
        	@brief Constructeur du compte racine
        	@param n: const string&, le nom du compte racine
        	@param t: Type, le type du compte
    	*/

    	CompteRacine(const string& n, Type t):CompteVirtuel(n,t){}
    	~CompteRacine()=default;
};


#endif // COMPTERACINE_H_INCLUDED
