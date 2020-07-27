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

class Transaction;

class Operation {

private:

    /**
        @var string Operation::debit
        @brief Débit de l'opération.
    */
    double debit;
    /**
        @var string Operation::credit
        @brief Crédit de l'opération.
    */

    double credit;
    /**
        @var string Operation::trans
        @brief Transaction liée à l'opération.
    */



    Transaction* trans = nullptr;

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

        Operation(const double d, const double c, CompteReel& co): debit(d), credit(c), compte(co){}

    /**
        @fn double Operation::getDebit() const
        @return Permet de retourner le débit de l'opération.
    */

    double getDebit() const{return debit;}


    /**
        @fn double Operation::getCredit() const
        @return Permet de retourner le crédit de l'opération.
    */

    double getCredit() const{return credit;}

    /**
        @fn Transaction& Operation::getTrans() const
        @return Permet de retourner la transaction liée à l'opération.
    */

    Transaction& getTrans() const{return *trans;}

    /**
        @fn CompteReel& Operation::getCompte() const
        @return Permet de retourner le compte lié à l'opération.
    */

    CompteReel& getCompte() const {return compte;}

    /**
        @brief modifie la valeur du credit de l'opération
    */
    void setCredit(double credit){

            credit = credit;
    }
    /**
           @brief modifie la valeur du debit de l'opération
    */
    void setDebit(double debit){

            debit = debit;
    }


    /**@return Vrai si l'operation n'a pas été modifiée, faux sinon
     **/
    bool checkValidite();

    /** @brief Déclaration d'amitié entre Opération et TransactionManager.
    */
    friend class Transaction;



};

#endif

