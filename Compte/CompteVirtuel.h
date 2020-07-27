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
    
    /**
		@fn CompteVirtuel::CompteVirtuel(const string& n, Type t).
		@brief Constructeur de compte virtuel.
		@param n: const string&, nom du compte
		@param t: Type, type du compte
	*/

	CompteVirtuel(const string& n, Type t):Compte(n,t){}

    /**
		@fn void CompteVirtuel::creerFils(const string& c, int solde, Type t).
		@brief Permet de créer un compte fils d'un compte virtuel.
		@param Pointeur sur le compte à insérer en fils
	*/
	
  void creerFils(Compte* c);

    /**
		@fn void CompteVirtuel::supprimerFils(Compte& c).
		@brief Permet de supprimer un compte fils d'un compte virtuel.
		@param c: Compte&, référence sur le nompte à supprimer
	*/
	
    void supprimerFils (Compte& c);

    /**
		@fn TypeCompte CompteVirtuel::getTypeCompte() const;
		@return Retourne le type de poste du compte.
	*/

   TypeCompte getTypeCompte() const;

	/**
		@fn string CompteVirtuel::toString() const;
		@return Retourne un string descriptif du compte (type, nom, poste, solde).
	*/

	string toString() const;

	/**
		@fn void CompteVirtuel::afficher(int profondeur) const;
		@return Affiche le compte réel;
		@param profondeur: int, permet de gérer la profondeur d'affichage du compte en fonction de sa hiérarchie (récursivité)
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
		@param n: const string&, le nom du compte à rechercher
	*/

	Compte& getCompteByNom(const string& n);

	/**
		@fn   bool CompteVirtuel::existeNom(const string &n) const;
		@return True si le nom existe dans la hiérarchie.
		@param n: const string&, le nom du compte à rechercher
	*/

	bool existeNom(const string &n) const;

	 /**
		@fn   Compte& CompteVirtuel::getPere(const Compte& c);
		@return Retourne une référence sur le père du compte
		@param c: const Compte&, une référence sur le compte dont on doit rechercher le père (récursivité)
	*/

	Compte& getPere(const Compte& c);

	 /**
		@fn double CompteVirtuel::getSolde() const.
		@brief Permet d'obtenir le solde d'un compte.
		@return Le solde du compte
	*/

	double getSolde() const;
	
	/**
		@fn bool CompteVirtuel::isFils(const Compte& c) const;
		@brief Permet de vérifier si un compte passé en paramètre est dans la sous-hiérarchie du compte virtuel
		@return Un booléen: VRAI si le compte est dans sa sous-hiérarchie, FAUX sinon
	*/

	bool isFils(const Compte& c) const;
	
	/**
		@fn double CompteVirtuel::cloturer(vector<Operation*> &o,Type t);
		@brief Permet de cloturer le livre
		@return Retourne la somme des soldes des sous-comptes réels
		@param o: vector<Operation*>&, une référence sur un vecteur d'opération à remplir
		@param t: Type, le type à cloturer (recette ou dépense)
	*/
	
	double cloturer(vector<Operation*> &o,Type t);

private:
	/**
        	@var vector<Compte*> fils
        	@brief Correspond à l'ensemble des fils du Compte Virtuel.
   	 */

	vector<Compte*> fils;

};

#endif
