/**************************************
    @file Operation.cpp
    @brief Implémentation de la classe opération
    @version v2
    @date 14 juin 2020
    @bug aucun détecté
    @warning COMPILE
    @note
    
    **********************************/


#include "Operation.h"
#include <sstream>



void Operation::editer_operation() {
    
    if (getDebit() < 0.00)
    {
        setCredit(getCredit() - getDebit());
        setDebit(0.00);
        cout<<"le debit était négatif, l'opération a été modifiée\n";
    }
    if (getCredit() <  0.00)
    {
        setDebit(getDebit() - getCredit());
        setCredit(0.00);
        cout<<"le crédit était négatif, l'opération a été modifiée\n";
    }
    if (getDebit() !=  0.00 && getCredit() !=  0.00) {
        if (getDebit()>getCredit()) {
            setDebit(getDebit() - getCredit());
            setCredit( 0.00);
        }
        else{
            setCredit(getCredit() - getDebit());
            setDebit( 0.00);
        }
        cout<<"ni le debit ni le credit n'était nul, l'opération a été modifiée.\n";
    }
    return;
}

ostream& operator<<(ostream& f, const Operation& op) {

	stringstream s_compte;
        stringstream s_credit;
        stringstream s_debit;
        
        s_compte<<" "<<op.getCompte().getNom();
        s_credit<<" "<<op.getCredit();
        s_debit<<" "<<op.getDebit();
        
        cout<<"│"<<s_compte.str();
        for (int i=0;i<(30-s_compte.str().size());i++) cout<<" ";
        cout<<"│"<<s_debit.str();
        for (int i=0;i<(14-s_debit.str().size());i++) cout<<" ";
        cout<<"│"<<s_credit.str();
        for (int i=0;i<(14-s_credit.str().size());i++) cout<<" ";
        cout<<"│\n";
        
    return f;
}

