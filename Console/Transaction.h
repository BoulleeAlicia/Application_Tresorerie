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
    @brief Transaction classe concrète qui correspondra à 2 comptes réels (donc 2 opérations) au moins.
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
        @brief reference de la Transaction.
    */
    int reference;
    /**
        @var string Transaction::memo
        @brief memo de la Transaction.
    */
    string memo;
    /**
        @var bool Transaction::marque
        @brief rapprochement de la transaction.
    */
    bool marque=false;
    /**
        @var vector<Operation*> Transaction::operations
        @brief Correspond à l'ens2emble des Operations dans la Transaction.
    */
    vector<Operation*> operations;
    /**
        @fn Transaction(const Date& d, int r, const string& m, bool m, list <Operation*> o):date(d),reference(r), memo(m), marque(m), operations(o).
        @return Permet de construire une instance de la classe Transaction.
    */
    Transaction(const TIME::Date& d, int r, const string& me, vector<Operation*> o) : date(d), reference(r), memo(me), operations(o) {}
    /**
        @fn Transaction(const Transaction& tr).
        @return Permet de construire une copie d'une transaction precise.
    */
    Transaction(const Transaction& tr);
    /**
        @fn ~Transaction().
        @return Permet de detruitre une instance de la classe Transaction.
    */
    ~Transaction();
    /**
        @fn vector<Operation*> Creation_Vector_Operations( vector<Operation*> operations , operation* operation ).
        @return Permet de creer le vecteur d'operations qu'on va utiliser dans la construction de la transaction
    */
    vector<Operation*> Ajout_Vector_Operations( Transaction* transaction , double d, double c, CompteReel& CO );
    /**
        @fn bool Validation_Vector_Operations( vector <Operation*> operations ).
        @return Permet de valider la conformite du vecteur d'operations
    */
    bool Validation_Vector_Operations( vector <Operation*> operations );
    /**
        @fn void Modification_Vector_Operations( Transaction* transaction ).
        @return Permet de modifier le vecteur des operations
    */
    void Modification_Vector_Operations( Transaction* transaction );
    /**
        @fn void Reverse_Transaction( vector<Operation*> operations ).
        @return Permet d'annuler les operations crediter et debiter effectuer lors d'une transaction
    */
    void Reverse_Transaction( vector<Operation*> operations );

public:

    friend class TransactionManager;
    /**
        @fn date Transaction::getDate() const
        @return Permet de retourner la date de la Transaction.
    */
    TIME::Date getDate() const { return date; }
    /**
        @fn int Transaction::getReference() const
        @return Permet de retourner la Reference de la Transaction.
    */
    int getReference() const { return reference; }
    /**
        @fn string Transaction::getMemo() const
        @return Permet de retourner le Memo de la Transaction.
    */
    string getMemo() const { return memo; }
    /**
        @fn bool Transaction::getMarque() const
        @return Permet de savoir si la Transaction a été rapprochée.
    */
    bool getMarque() const { return marque; }
    /**
        @fn list<Operation*> Transaction::getOperation() const
        @return Permet de retourner un pointeur sur les opérations qui font partie de la Transaction.
    */
    vector<Operation*> getOperation() const { return operations; }
    /**
        @fn void setDate(TIME::Date date)
        @return Permet de modifier la date de la transaction
    */
    void setDate(TIME::Date date) { this->date = date; }
    /**
        @fn void setReferance(int reference)
        @return Permet de modifier la Reference de la transaction
    */
    void setReference(int reference) { this->reference = reference; }
    /**
        @fn void setMemo(string memo)
        @return Permet de modifier la Memo de la transaction
    */
    void setMemo(string memo) { this->memo = memo; }
    /**
        @fn void setMarque(string memo)
        @return Permet de modifier le Marquage de la transaction
    */
    void setMarque(bool marque) { this->marque = marque; }
    /**
        @fn void setOperation( vector<Operation*> new_operations )
        @return Permet de modifier le vector d'operation d'une transaction percise
    */
    void setOperation( vector<Operation*> new_operations ) { this->operations = new_operations ; }

};

#endif
