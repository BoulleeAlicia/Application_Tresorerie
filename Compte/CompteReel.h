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
		@param n: const string&, le nom du compte
		@param t: Type, le type du compte,
		@param s: double, le solde initial du compte
	*/

	CompteReel(const string& n, Type t, double s):Compte(n,t),solde(s){}

    /**
		@fn void CompteReel::crediter(double m).
		@brief Permet de créditer un compte réel d'un montant m.
		@param m: double, le montant à créditer
		@exception "ERREUR: Operation impossible car le montant est inferieur a 0"
	*/
    void crediter(double m);

    /**
		@fn void CompteReel::debiter(double m).
		@brief Permet de débiter un compte réel un montant m.
		@param m: double, le montant à créditer
		@exception "ERREUR: Operation impossible car le montant est inferieur a 0"
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
		@return Retourne un string descriptif du compte (type, nom, poste, solde).
	*/

    string toString() const;

    /**
		@fn void CompteReel::afficher(int profondeur) const;
		@brief Affiche le compte réel;
		@param profondeur: int, permet d'afficher le compte avec la bonne profondeur en fonction de sa hiérarchie
	*/


    void afficher(int profondeur) const;

     /**
		@fn  Compte& CompteReel::getCompteByNom(const string& n);
		@return Retourne une référence sur le compte du nom passé en argument
		@param n: const string&, le nom du compte à rechercher
	*/

    Compte& getCompteByNom(const string& n);

    /**
		@fn   Compte& CompteReel::getPere(const Compte& c);
		@return Retourne une référence sur le père du compte
		@param c: const Compte&, une référence sur le compte dont on doit chercher le père
	*/

    Compte& getPere(const Compte& c);

    /**
		@fn   bool CompteReel::existeNom(const string &n) const;
		@return Un booléen true si le nom existe dans la hiérarchie.
		@param n: const string&, le nom du compte dont on doit vérifier l'existence
	*/

    bool existeNom(const string &n) const;
    
    /**
		@fn   bool CompteReel::isFils(const Compte& c) const
		@return Vrai si le compte passé en paramètre se trouve dans sa hiérarchie de fils (fonction récursive)
		@param c: const Compte&, une référence sur le fils à chercher
	*/

	bool isFils(const Compte& c) const
	{return (this==&c);
	}
	
private:

	/**
        	@var double CompteReel::solde
        	@brief Correspond au solde du compte réel.

    */

	double solde;

};

#endif
