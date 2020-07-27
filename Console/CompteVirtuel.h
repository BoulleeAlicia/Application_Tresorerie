#ifndef COMPTEVIRTUEL_H_INCLUDED
#define COMPTEVIRTUEL_H_INCLUDED

/***********************************************************************************
	@file Comptevirtuel.h
	@brief Définition de la classe CompteVirtuel
	@version v3
	@date 9 juin 2020
	@bug aucun détecté
   	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Compte.h"
#include "Operation.h"

using namespace std;


    /**
        @class CompteVirtuel "CompteVirtuel.h"
        @brief Classe CompteVirtuel qui hérite de la classe abstraite Compte.

    */

class CompteVirtuel : public Compte{
friend class CompteManager;
public :
	CompteVirtuel(const string& n, Type t):Compte(n,t){}

    /**
		@fn CompteVirtuel::creerFils(const string& c, int solde, Type t).
		@brief Permet de créer un compte fils d'un compte virtuel.
	*/
  void creerFils(Compte* c);


    /**
		@fn CompteVirtuel::supprimerFils(Compte* c).
		@brief Permet de supprimer un compte fils d'un compte virtuel.
		@return Rien.
	*/
    void supprimerFils (Compte& c);


  /**
		@fn TypeCompte CompteVirtuel::getTypeCompte() const;
		@return Retourne le type de poste du compte.
	*/




   TypeCompte getTypeCompte() const;

	/**
		@fn string CompteVirtuel::toString() const;
		@return Retourne un string descriptif du compte.
	*/

	string toString() const;

	/**
		@fn void CompteVirtuel::afficher(int profondeur) const;
		@return Affiche le compte réel;
	*/

	void afficher(int profondeur) const;

	/**
		@fn  vector<Compte*> CompteVirtuel::getFils() const
		@return Retourne le vector de comptes fils
	*/


	vector<Compte*> getFils() const{return fils;}

	/**
		@fn  Compte& CompteVirtuel::getCompteByNom(const string& n);
		@return Retourne une référence sur le compte du nom passé en argument
	*/

	Compte& getCompteByNom(const string& n);

	/**
		@fn   bool CompteVirtuel::existeNom(const string &n) const;
		@return Test d'existence du nom dans la hiérarchie.
	*/

	bool existeNom(const string &n) const;

	 /**
		@fn   Compte& CompteVirtuel::getPere(const Compte& c);
		@return Retourne une référence sur le père du compte
	*/

	Compte& getPere(const Compte& c);

	 /**
		@fn CompteVirtuel::getSolde() const.
		@brief Permet d'obtenir le solde d'un compte.
		@return
	*/

	double getSolde() const;

	bool isFils(const Compte& c) const;
	
	double cloturer(vector<Operation*> &o,Type t);

private:
	/**
        	@var list<Compte*> fils
        	@brief Correspond à l'ensemble des fils du Compte Virtuel.
   	 */

	vector<Compte*> fils;

};

#endif
