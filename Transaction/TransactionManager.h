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
        @fn  vector<Transaction*> TransactionManager::getTransactions();
        @brief Méthode pour recuperer toutes les transactions
        @return Un vecteur de pointeur sur transactions
    */
    vector<Transaction*> getTransactions() const{return trans;}
    
    /**
        @fn  Transaction* TransactionManager::getTransaction(r: int);
        @brief Méthode pour recuperer une transaction.
        @param r : int, la reference de la transaction qu'on cherche
        @return Un pointeur sur l'instance de la Transaction que l'on cherche.
    */
    Transaction* getTransaction(int r);
    /**
        @fn  void TransactionManager::ajouterTransaction (d:const date&, r:integer, m:const string&, marque:integer, o:vector<Operation*>);
        @param d : Date&, la date de la transaction
        @param r : const int, la reference de la transaction à ajouter
        @param m : const string&, le memo de la transaction à ajouter
        @param o : vector<Operation*>, un vecteur de pointeurs d'operation de la transaction à ajouter
        @brief Méthode pour creer et ajouter une Transaction dans TransactionManager.
        @exception "ERREUR: La transaction n'existe pas"
    */
    void ajouterTransaction (const TIME::Date& d,const int r, const string& m, vector<Operation*>o);
    /**
        @fn  void TransactionManager::supprimerTransaction (r: int);
        @param r : int, la reference de la transaction à supprimer
        @brief Méthode pour supprimer une Transaction de TransactionManager.
        @exception "ERREUR: La transaction existe déjà"
    */
    void supprimerTransaction (int r);
    /**
        @fn  void TransactionManager::editerTransaction (r: int);
        @param r : int, la reference de la transaction à editer
        @brief Méthode pour editer une Transaction dans TransactionManager.
        @exception "ERREUR: Impossible de supprimer une transaction rapprochée"
        @exception "ERREUR: La transaction n'existe pas"
     */
    void editerTransaction (int r);
    /**
        @fn  void TransactionManager::afficherTransactions();
        @brief Méthode pour afficher les Transactions de TransactionManager.
        @exception "ERREUR: Impossible de modifier une transaction rapprochée"
        @exception "ERREUR: La transaction n'existe pas"
    */
    void afficherTransactions();
    /**
        @fn  void TransactionManager::afficherTransactionsCompte(CompteReel& c);
        @param c : CompteReel&, une reference sur le compte reel dont on veut afficher les transactions liées
        @brief Méthode pour afficher les Transactions liées à un compte.
        @exception "ERREUR: Il n'y a pas de transaction"

    */
    void afficherTransactionsCompte(CompteReel& c);
    
    /**
           @fn  bool UsageCompte( CompteReel& c );
           @param c : CompteReel&, une reference sur le compte reel dont on veut savoir s'il a des transactions liées.
           @brief Méthode pour savoir si un compte est lié à des transactions.
           @return Renvoie un booléen qui est vrai si le compte est lié à des transactions
           @exception ERREUR: Le compte n'a pas des transaction"

    */
    bool UsageCompte( CompteReel& c );
    
    /**
        @fn  vector<Transaction*> getTransactionsByCompte(const CompteReel& c);
        @param c : CompteReel&, une reference sur le compte reel dont on veut obtenir les transactions liées
        @brief Méthode pour obtenir les Transactions liées à un compte.
        @return Renvoie un vecteur de pointeurs de transactions, celles liées au compte passé en paramètre

    */
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
           @var vector<Transaction*> trans;
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

