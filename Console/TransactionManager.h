#ifndef TRANSACTIONMANAGER_H_INCLUDED
#define TRANSACTIONMANAGER_H_INCLUDED
/***********************************************************************************
	@file TransactionManager.h
	@brief TransactionManager permet de gérer l'emsemble des Transactions
	@version v1
	@date 3 juin 2020
	@bug aucun détecté
    	@warning COMPILE
	@note
***********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include<stdexcept>
#include "Transaction.h"
#include "Operation.h"



using namespace std;

/**
	@class TransactionManager "TransactionManager.h"
	@brief TransactionManager permet de gérer l'emsemble des Transactions.
*/

class TransactionManager{
public:
	/**
		@fn  TransactionManager& TransactionManager::getIstance();
		@brief Méthode implémentant le design pattern Singleton.
		@return Une référence sur l'unique instance du TransactionManager.
	*/
	static TransactionManager& getInstance();
	
	
	/**
		@fn  vector<Transaction*> TransactionManager::getTransaction(r: int);
		@brief Méthode pour recuperer une transaction.
		@return Une pointeur sur l'instance du Transaction.
	*/
	vector<Transaction*> getTransactions() const{return trans;}
	
	/**
		@fn  Transaction* TransactionManager::getTransaction(r: int);
		@brief Méthode pour recuperer une transaction.
		@return Une pointeur sur l'instance du Transaction.
	*/
	Transaction* getTransaction(int r);
	/**
		@fn  void TransactionManager::ajouterTransaction (d:const date&, r:integer, m:const string&, marque:integer, o:vector<Operation*>);
		@brief Méthode pour creer et ajouter une Transaction sur TransactionManager.
		@return Rien.
	*/
	void ajouterTransaction (const TIME::Date& d,const int r, const string& m, vector<Operation*>o);
	/**
		@fn  void TransactionManager::supprimerTransaction (r: int);
		@brief Méthode pour supprimer une Transaction dans TransactionManager.
		@return Rien.
	*/
	void supprimerTransaction (int r);
	/**
		@fn  void TransactionManager::editerTransaction (r: int);
		@brief Méthode pour editer une Transaction dans TransactionManager.
		@return Rien.
	*/
	void editerTransaction (int r);
	/**
		@fn  void TransactionManager::afficherTransactions();
		@brief Méthode pour afficher les Transaction dans TransactionManager.
		@return Rien.
	*/
	void afficherTransactions();
	/**
		@fn  void TransactionManager::afficherTransactionsCompte();
		@brief Méthode pour afficher les Transaction dans TransactionManager d'une Compte.
		@return Rien.
	*/
	void afficherTransactionsCompte(CompteReel& c);

bool UsageCompte( CompteReel& c );

vector<Transaction*> getTransactionsByCompte(const CompteReel& c);

    TransactionManager() = default;
    ~TransactionManager();

private:
	/**
       	@var static TransactionManager TransactionManager::instance
       	@brief Correspond à l'unique instance du TransactionManager (pour design pattern Singleton).
    */
	static TransactionManager instance;
	/**
       	@var list<Transaction*> trans
       	@brief Correspond à l'ensemble des Transactions dans TransactionManager.
    */
	vector<Transaction*> trans;
	/**
       	@var string TransactionManager::filename.
       	@brief Correspond au chemin du fichier qui stocke l'ensemble des Transactions.
    */
	string filename;

};

#endif
