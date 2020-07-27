#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED

/***********************************************************************************
	@file Compte.h
	@brief Compte classe abstraite qui pourra être à la fois un compte virtuel ou réel.
	@version v3
	@date 9 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Erreur.h"

using namespace std;

enum Type{actif,passif,depense,recette,racine};
enum TypeCompte{virtuel,reel};

/**
	@class Compte "Compte.h"
	@brief Compte classe abstraite qui pourra être à la fois un compte virtuel ou réel.
*/

class Compte{
friend class CompteManager;
public :
	/**
		@fn string Compte::getNom() const
		@return Permet de retourner le nom du compte.
	*/

	string getNom() const{return nom;}

	/**
		@fn Type Compte::getType() const
		@return Permet de retourner le type du compte.
	*/

	Type getType() const{return type;}

	/**
		@fn virtual TypeCompte Compte::getTypeCompte() const=0;
		@brief Fonction virtuelle pure donnant le type de compte (virtuel ou réel).
	*/

	virtual TypeCompte getTypeCompte() const=0;

	/**
		@fn virtual string Compte::toString() const=0;
		@brief Fonction virtuelle pure renvoyant un descriptif sous forme de string du compte.
	*/

	virtual string toString() const=0;

	/**
		@fn virtual void Compte::afficher(int profondeur) const=0;
		@brief Fonction virtuelle pure qui affiche la hiérarchie des comptes.
	*/

	virtual void afficher(int profondeur) const=0;

	/**
		@fn virtual double Compte::getSolde() const=0;
		@brief Fonction virtuelle pure qui donne le solde du compte.
	*/

	virtual double getSolde() const=0;

	/**
		@fn virtual bool Compte::existeNom(const string &n) const=0;
		@brief Fonction virtuelle pure qui vérifie si le nom de compte existe.
		@param n: const string&, une chaine de caractères correspondant à un nom de compte
	*/

	virtual bool existeNom(const string &n) const=0;
	
	/**
		@fn virtual bool Compte::isFils(const Compte &c) const=0;
		@brief Fonction virtuelle pure qui vérifie si le compte envoyé en paramètre est le fils du compte.
		@param c: const Compte&, le compte qui sera envoyé sera recherché dans les fils du compte
	*/
	
	virtual bool isFils(const Compte &c) const=0;

	Compte()=delete;
	~Compte()=default;
	
protected:
	/**
        	@var string Compte::nom
        	@brief Nom du Compte.
    */

	string nom;

	/**
        	@var Type Compte::type
        	@brief Type du Compte.
    */
	Type type;
	
	/**
		@fn Compte::Compte(const string& n, Type t).
		@brief Permet de construire une instance de la classe Compte.
		@param n: const string&, le nom du compte
		@param t:Type, le type du compte
	*/

	Compte(const string& n, Type t):nom(n),type(t){}
};

#endif // COMPTE_H_INCLUDED
