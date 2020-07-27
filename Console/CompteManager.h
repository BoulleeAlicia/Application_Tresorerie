#ifndef COMPTEMANAGER_H_INCLUDED
#define COMPTEMANAGER_H_INCLUDED
/***********************************************************************************
	@file CompteManager.h
	@brief CompteManager permet de gérer l'emsemble des comptes.
	@version v3
	@date 17 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include <string>
#include "TransactionManager.h"

#include "CompteRacine.h"
#include "CompteReel.h"
#include "CompteVirtuel.h"

using namespace std;

/**
	@class CompteManager "CompteManager.h"
	@brief CompteManager permet de gérer l'emsemble des comptes.
*/
class CompteManager{

public :
	/**
		@fn  CompteManager& CompteManager::getInstance()
		@brief Méthode implémentant le design pattern Singleton.
		@return Une référence sur l'unique instance du CompteManager.
	*/
	static CompteManager& getInstance();

	/**
		@fn  CompteRacine& CompteManager::getRacine() const{return rac.getInstance();};
		@return Renvoie une référence sur le compte racine
	*/

	CompteRacine& getRacine() const{return rac.getInstance();};

	/**
		@fn  void CompteManager::creerCompte(Compte& p, const string& n, Type t, double s);
		@brief Méthode permettant de créer un compte dans le compte transmis en argument.
	*/
	
	void creerCompte(Compte& p, const string& n, Type t, TypeCompte tc);
	
	void creerCompte(Compte& p, const string& n, Type t, double s, TypeCompte tc);

	/**
		@fn  void CompteManager::afficher() const;
		@brief Affiche l'intégralité de l'arborescence des comptes.
	*/

	void afficher() const;

	/**
		@fn  void CompteManager::supprimerCompte(Compte& c);
		@brief Permet de supprimer le compte passé en paramètre
	*/

	void supprimerCompte(Compte& c);

	/**
		@fn  bool CompteManager::existeNom(const string &n) const;
		@brief Permet de tester l'existence ou nom du nom de Compte passé en paramètre
	*/

	bool existeNom(const string &n) const;

	/**
		@fn  Compte& CompteManager::getCompteByNom(const string &n);
		@return Retourne une référence sur le nom du compte passé en argument.
	*/

	Compte& getCompteByNom(const string &n);

	/**
		@fn  Compte& CompteManager::getPere(const Compte& c);
		@return Retourne une référence sur le compte passé en paramètre
	*/

	Compte& getPere(const Compte& c);

    /**
		@fn CompteManager::editerCompte(Compte& c, const string& n, Type t);
		@brief Permet d'éditer le nom et/ou le type d'un compte
		@return Rien.
	*/
   void editerCompte(Compte& c, const string& n);

	void deplacerCompte(Compte& p, Compte& c);

void cloturer();

void rapprocher(const CompteReel& c);

bool isRapproche(const CompteReel& c);

private:
	/**
        	@var string CompteManager::filename.
        	@brief Correspond au chemin du fichier qui stocke l'ensemble des comptes.
    	*/
	string filename;

	//Rendre privée la duplication
	CompteManager& operator= (const CompteManager&){}
   	CompteManager (const CompteManager&){}

	/**
        	@var static CompteManager CompteManager::instance
        	@brief Correspond à l'unique instance du compte racine (pour design pattern Singleton).
    	*/

    	static CompteManager instance;

    	/**
        	@var string static CompteRacine CompteManager::rac.
        	@brief Instance du compte racine.
    	*/

    	static CompteRacine rac;

    	CompteManager()=default;
    	~CompteManager()=default;
};

#endif // COMPTEMANAGER_H_INCLUDED
