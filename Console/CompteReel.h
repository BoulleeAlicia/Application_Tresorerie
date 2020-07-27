#ifndef COMPTEREEL_H_INCLUDED
#define COMPTEREEL_H_INCLUDED

/***********************************************************************************
	@file CompteReel.h
	@brief Définition de la classe CompteReel
	@version v2
	@date 9 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include <string>
#include "Compte.h"
#include "Erreur.h"

using namespace std;

/**
	@class Compte Réel "CompteReel.h"
	@brief Classe Compte Réel qui hérite de la classe abstraite Compte.

*/

class CompteReel : public Compte{
friend class CompteManager;
public :
	/**
		@fn double CompteReel::CompteReel(const string& n, Type t, double s).
		@brief Constructeur de CompteReel.
	*/

	CompteReel(const string& n, Type t, double s):Compte(n,t),solde(s){}

    /**
		@fn void CompteReel::crediter(double m).
		@brief Permet de créditer un compte réel d'un montant m.
	*/
    void crediter(double m);



    /**
		@fn void CompteReel::debiter(double m).
		@brief Permet de débiter un compte réel un montant m.
	*/
    void debiter(double m);


    	/**
		@fn double CompteReel::getSolde() const.
		@brief Permet d'obtenir le solde d'un compte réel.
		@return Retourne le solde d'un compte réel.
	*/

	 double getSolde() const;

    /**
		@fn TypeCompte CompteReel::getTypeCompte() const;
		@return Retourne le type de poste du compte.
	*/

    TypeCompte getTypeCompte() const;

     /**
		@fn string CompteReel::toString() const;
		@return Retourne un string descriptif du compte.
	*/

    string toString() const;

    /**
		@fn void CompteReel::afficher(int profondeur) const;
		@return Affiche le compte réel;
	*/


    void afficher(int profondeur) const;

     /**
		@fn  Compte& CompteReel::getCompteByNom(const string& n);
		@return Retourne une référence sur le compte du nom passé en argument
	*/

    Compte& getCompteByNom(const string& n);

    /**
		@fn   Compte& CompteReel::getPere(const Compte& c);
		@return Retourne une référence sur le père du compte
	*/

    Compte& getPere(const Compte& c);

    /**
		@fn   bool CompteReel::existeNom(const string &n) const;
		@return Test d'existence du nom dans la hiérarchie.
	*/

    bool existeNom(const string &n) const;

	bool isFils(const Compte& c) const
	{return (this==&c);
	}
private:
	/**
        	@var vector<Operation*> CompteReel::operations
        	@brief Correspond à l'ensemble des opérations du compte réel.
    */

	//vector <Operation*> operations;


	/**
        	@var double CompteReel::solde
        	@brief Correspond au solde du compte réel.

    */

	double solde;

};

#endif
