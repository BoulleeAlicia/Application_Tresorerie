/***********************************************************************************
    @file Transaction.h
    @brief Transaction classe concrète qui correspondra à 2 comptes réels (donc 2 opérations) au moins.
    @version v7
    @date 15 juin 2020
    @bug aucun détecté
    @warning COMPILE
    @note
***********************************************************************************/
#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "timing.h"
#include "Operation.h"
#include "CompteManager.h"

using namespace std;

class Operation ;

/**
    @class Transaction "Transaction.h"
    @brief Transaction classe concrète qui correspond à 2 comptes réels (donc 2 opérations) au moins.
*/
class Transaction{

friend class CompteManager;
  private:

    /**
        @var date Transaction::date
        @brief date de la Transaction.
    */
    TIME::Date date;
    /**
        @var int Transaction::reference
        @brief Correspond à la ref de la Transaction.
    */
    int reference;
    /**
        @var string Transaction::memo
        @brief Correspond au memo de la Transaction.
    */
    string memo;
    /**
        @var bool Transaction::marque
        @brief Permet de savoir si la transaction a été rapprochée (initialisée à false)
    */
    bool marque=false;
    /**
        @var vector<Operation*> Transaction::operations
        @brief Correspond à l'ensemble des Operations de la Transaction.
    */
    vector<Operation*> operations;
    /**
        @fn Transaction(const Date& d, int r, const string& m, vector <Operation*> o):date(d),reference(r), memo(m), operations(o).
        @param d : Date&, reference sur la date de la transaction
        @param r : int, ref de la transaction
        @param me : const string&, memo de la transaction
        @param o : vector <Operation*>, vecteur de pointeurs d'operations de la transaction
        @brief Permet de construire une instance de la classe Transaction.
    */
    Transaction(const TIME::Date& d, int r, const string& me, vector<Operation*> o) : date(d), reference(r), memo(me), operations(o) {}
    /**
        @fn Transaction(const Transaction& tr).
        @brief Permet de construire une copie d'une transaction precise.
        @param tr: const Transaction&
    */
    Transaction(const Transaction& tr);
    /**
        @fn ~Transaction().
        @brief Permet de detruitre une instance de la classe Transaction.
    */
    ~Transaction();
    /**
        @fn vector<Operation*> Creation_Vector_Operations( vector<Operation*> operations , operation* operation ).
        @param transaction : Transaction&, pointeur sur la transaction qu'on crée
        @param d : double, qui correspond au debit de l'operation
        @param c : double qui correspond au credit de l'operation
        @param CO : CompteReel& qui correspond au compte de l'opération
        @brief Permet de creer le vecteur d'operations qu'on va utiliser dans la construction de la transaction
        @return Retourne le vecteur d'opérations créé
    */
    vector<Operation*> Ajout_Vector_Operations( Transaction* transaction , double d, double c, CompteReel& CO );
   
    /**
        @fn bool Validation_Vector_Operations( vector <Operation*> operations )
        @param operations : vector <Operation*>, le vecteur de pointeur d'operations de la future transaction
        @brief Permet de creer le vecteur d'operations qu'on va utiliser dans la construction de la transaction
        @return Retourne un booléen: VRAI si le vecteur est bon, FAUX sinon
    */
    bool Validation_Vector_Operations( vector <Operation*> operations );
    
    /**
        @fn void Modification_Vector_Operations( Transaction* transaction )
        @param transaction : Transaction*, un pointeur sur la transaction qui contient les opérations à modifier
        @brief Permet de modifier le vecteur des operations si non valide
    */
    void Modification_Vector_Operations( Transaction* transaction );
    /**
        @fn void Reverse_Transaction( vector<Operation*> operations ).
        @param operations :  vector<Operation*>, le vector de pointeurs d'operations de la transaction
        @brief Permet d'annuler les operations crediter et debiter effectuées lors d'une transaction
    */
    void Reverse_Transaction( vector<Operation*> operations );

public:

    friend class TransactionManager;
    /**
        @fn date Transaction::getDate() const
        @return la date de la Transaction.
    */
    TIME::Date getDate() const { return date; }
    /**
        @fn int Transaction::getReference() const
        @return Un integer qui est la Ref de la Transaction.
    */
    int getReference() const { return reference; }
    /**
        @fn string Transaction::getMemo() const
        @return Un string qui est le memo de la Transaction.
    */
    string getMemo() const { return memo; }
    /**
        @fn bool Transaction::getMarque() const
        @return Un booléen qui permet de savoir si la Transaction a été rapprochée.
    */
    bool getMarque() const { return marque; }
    /**
        @fn list<Operation*> Transaction::getOperation() const
        @return Un vecteur de pointeurs sur les opérations qui font partie de la Transaction.
    */
    vector<Operation*> getOperation() const { return operations; }
    /**
        @fn void setDate(TIME::Date date)
        @brief Permet de modifier la date de la transaction
    */
    void setDate(TIME::Date date) { this->date = date; }
    /**
        @fn void setReference(int reference)
        @brief Permet de modifier la ref de la transaction
    */
    void setReference(int reference) { this->reference = reference; }
    /**
        @fn void setMemo(string memo)
        @brief Permet de modifier la Memo de la transaction.
    */
    void setMemo(string memo) { this->memo = memo; }
    /**
        @fn void setMarque(string memo)
        @brief Permet de marquer une transaction.
    */
    void setMarque(bool marque) { this->marque = marque; }
    /**
        @fn void setOperation( vector<Operation*> new_operations )
        @brief Permet de modifier le vector d'operation d'une transaction
    */
    void setOperation( vector<Operation*> new_operations ) { this->operations = new_operations ; }

};

#endif
