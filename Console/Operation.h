#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
/***********************************************************************************
    @file Operation.h
    @brief Operation classe concrète qui renseigne les informations d'une transaction pour un compte réel
    @version v1
    @date 4 juin 2020
    @bug aucun détecté
    @warning COMPILE
    @note
***********************************************************************************/



#include <iostream>
#include <string>
#include "CompteReel.h"
#include "Erreur.h"

using namespace std;

/**
    @class Operation "Operation.h"
    @brief Operation classe concrète qui renseigne les informations d'une transaction pour un compte réel
*/

using namespace std;


class Operation {

private:

    /**
        @var string Operation::debit
        @brief Débit de l'opération.
    */
    double _debit;
    /**
        @var string Operation::credit
        @brief Crédit de l'opération.
    */

    double _credit;
 

    /**
        @var string Operation::compte
        @brief Compte lié à l'opération.
    */

    CompteReel& compte;

    /**
        @fn Operation::Operation(const double d, const double c, t const Transaction*, co const CompteReel*): debit(d), trans(t), credit(c), compte(co).
        @brief Permet de construire une instance de la classe Operation.
    */



public:

        Operation(const double d, const double c, CompteReel& co): _debit(d), _credit(c), compte(co){}

    /**
        @fn double Operation::getDebit() const
        @return Permet de retourner le débit de l'opération.
    */

    double getDebit() const{return _debit;}


    /**
        @fn double Operation::getCredit() const
        @return Permet de retourner le crédit de l'opération.
    */

    double getCredit() const{return _credit;}


    /**
        @fn CompteReel& Operation::getCompte() const
        @return Permet de retourner le compte lié à l'opération.
    */

    CompteReel& getCompte() const {return compte;}

    /**
        @brief modifie la valeur du credit de l'opération
    */
    void setCredit(double credit){

            _credit = credit;
    }
    /**
           @brief modifie la valeur du debit de l'opération
    */
    void setDebit(double debit){

            _debit = debit;
    }


    /**@return Vrai si l'operation n'a pas été modifiée, faux sinon
     **/
    void editer_operation();

    /** @brief Déclaration d'amitié entre Opération et TransactionManager.
    */
    friend class Transaction;



};

#endif


