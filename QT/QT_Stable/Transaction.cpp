/***********************************************************************************
    @file Transaction.cpp
    @brief Transaction classe concrète qui correspondra à 2 comptes réels (donc 2 opérations) au moins.
    @version v4
    @date 10 juin 2020
    @bug aucun détecté
    @warning COMPILE
    @note
***********************************************************************************/
#include <iostream>
#include "Transaction.h"
#include "Compte.h"
#include "CompteManager.h"

using namespace std;

/**
    @fn Transaction(const Transaction& tr).
    @return Permet de construire une copie d'une transaction precise.
*/
Transaction::Transaction(const Transaction& tr) : date(tr.getDate()), reference(tr.getReference()), memo(tr.getMemo()), marque(tr.getMarque())  {
    vector<Operation*> copie_operations ;
    Operation* copie_operation = nullptr ;
    for ( vector<Operation*>::iterator it = tr.getOperation().begin() ; it != tr.getOperation().end() ; ++it ) {
        copie_operation = *it ;
        copie_operations.push_back(copie_operation) ;
    }
    operations = copie_operations ;
}
/**
    @fn ~Transaction().
    @return Permet de detruitre une instance de la classe Transaction.
*/
Transaction::~Transaction() {
    for ( vector<Operation*>::iterator it = operations.begin() ; it != operations.end() ; ++it ) {
        delete *it;
    }
    operations.clear();
}
/**
    @fn vector<Operation*> Creation_Vector_Operations( vector<Operation*> operations , operation* operation ).
    @return Permet de creer le vecteur d'operations qu'on va utiliser dans la construction de la transaction
*/
vector<Operation*> Transaction::Ajout_Vector_Operations( Transaction* transaction , double debit, double credit, CompteReel& compte ) {
    vector<Operation*> Op = transaction->getOperation() ;
    Operation* op = new Operation( debit, credit, compte ) ;
    Op.push_back(op) ;
    transaction->setOperation(Op) ;
    return transaction->getOperation() ;
}
/**
    @fn bool Validation_Vector_Operations( vector <Operation*> operations ).
    @return Permet de valider la conformite du vecteur d'operations
*/
bool Transaction::Validation_Vector_Operations( vector <Operation*> operations ){
  if ( operations.size() < 2 ) {
    return false ;
  }
  double credit = 0.0 , debit = 0.0 ;
  for ( vector<Operation*>::iterator it = operations.begin() ; it != operations.end() ; ++it ){
    credit = credit + (*it)->getCredit() ;
    debit = debit + (*it)->getDebit() ;
  }
  if ( credit != debit ){
    return false ;
  }
  for ( vector<Operation*>::iterator it = operations.begin() ; it != operations.end() ; ++it ){
    ((*it)->compte).crediter((*it)->getCredit());
    ((*it)->compte).debiter((*it)->getDebit());
  }
  return true ;
}
/**
    @fn vector <Operation*> Modification_Vector_Operations( vector <Operation*> operations ) .
    @return Permet de modifier le vecteur des operations
*/
void Transaction::Supprimer_Vector_Operations ( Transaction* transaction ){
    transaction->Reverse_Transaction( transaction->getOperation() ) ;
    (transaction->getOperation()).clear() ;
    vector<Operation*> Op;
    transaction->setOperation(Op);
}

void Transaction::Modification_Vector_Operations( Transaction* transaction ) {
    transaction->Reverse_Transaction( transaction->getOperation() ) ;
    (transaction->getOperation()).clear() ;
    vector<Operation*> Op;
    int nb_op ;
    for ( unsigned int i = 0 ; i < nb_op ; i++ ){
        double debit , credit ;
        string n ;
        CompteReel& compte = dynamic_cast<CompteReel&>  (CompteManager::getInstance().getCompteByNom(n)) ;
        Operation* op = new Operation(debit, credit, compte);
        Op.push_back(op);
    }
    transaction->setOperation(Op);
    transaction->Validation_Vector_Operations( transaction->getOperation() ) ;
    return ;
}
/**
    @fn void Reverse_Transaction( vector<Operation*> operations ) .
    @return Permet d'annuler les operations crediter et debiter effectuer lors d'une transaction
*/
void Transaction::Reverse_Transaction( vector<Operation*> operations ) {
  for ( vector<Operation*>::iterator it = operations.begin() ; it != operations.end() ; ++it ){
    ((*it)->compte).crediter((*it)->getDebit());
    ((*it)->compte).debiter((*it)->getCredit());
  }
}
