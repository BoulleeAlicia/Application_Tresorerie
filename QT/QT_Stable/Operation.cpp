/**************************************
    @file Operation.cpp
    @brief Implémentation de la classe opération
    @version v1
    @date 6 juin 2020
    @bug aucun détecté
    @warning COMPILE
    @note

    **********************************/


#include "Operation.h"


ostream& operator<<(ostream& f, const Operation& op) {
    f << "Montant du Debit : " << op.getDebit()<<"\n\n";
    f << "Montant du Credit : " << op.getCredit() <<"\n\n";
    return f;
}


bool Operation::checkValidite() {


    if (getDebit() < 0)
    {

        setCredit(getCredit() - getDebit());
        setDebit(0.00);
    }
    else if (getCredit() < 0)
    {
        setDebit(getDebit() - getCredit());
        setCredit(0.00);
    }
    if (getDebit() != 0 && getCredit() != 0) {
        if (getDebit()>getCredit()) {
            setCredit(0);
            setDebit(getDebit() - getCredit());
        }
        else
            setDebit(0);
            setCredit(getCredit() - getDebit());
    }

   return (getDebit()==0 || getCredit()==0);
}



