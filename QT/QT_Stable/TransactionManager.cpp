
#include "TransactionManager.h"
#include "Erreur.h"

class Erreur;

using namespace std;

TransactionManager* TransactionManager::instance = nullptr;

TransactionManager& TransactionManager::getInstance()
{
    if(!instance){
        instance = new TransactionManager();
    }
    return *instance;
}

TransactionManager::~TransactionManager(){
    for(int i = trans.size()-1;i >= 0;i--){
            for(int j = trans[i]->operations.size()-1; j>=0; j--){
                delete trans[i]->operations[j];
                trans[i]->operations.pop_back();
            }
            delete trans[i];
            trans.pop_back();
    }
}

Transaction* TransactionManager::getTransaction(int r){
    try{
        for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
            if((*it)->getReference() == r){
                return *it;
            }
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }

    throw Erreur("La transaction n'existe pas\n");
}

void TransactionManager::ajouterTransaction (const QDate& d,const int r, const string& m, bool marque, vector<Operation*>o){
    try{
        for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
            if((*it)->getReference() == r){
                throw Erreur("La transaction existe deéjà\n");
            }
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }
    Transaction* new_trans = new Transaction(d,r,m,marque,o);
    trans.push_back(new_trans);

}

void TransactionManager::supprimerTransaction (int r){
    try{
        for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
            if((*it)->getReference() == r){
                for(int j = (*it)->operations.size()-1; j>=0; j--){
                    if((*it)->operations[j]->getDebit()>0){
                        (*it)->operations[j]->getCompte().crediter((*it)->operations[j]->getDebit());
                    }
                    else{(*it)->operations[j]->getCompte().debiter((*it)->operations[j]->getCredit());}
                    delete (*it)->operations[j];
                    (*it)->operations.pop_back();
                }
                delete (*it);
                trans.erase(it);
                return;
            }
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }
    throw Erreur("La transaction n'existe pas\n");
}
/*
void TransactionManager::editerTransaction (int r){
    //1-
    int i;
    cin>>i;
    try{
        for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
            if((*it)->getReference() == r){
                switch(i){
                case 0:{
                    TIME::Date new_date;
                    cin>>new_date;
                    (*it)->date = new_date;
                    break;
                }
                case 1:{
                    string new_memo;
                    cin>>new_memo;
                    (*it)->memo=new_memo;
                    break;
                }
                case 2:{
                    //(*it)->Modification_Vector_Operations((*it));
                    break;
                }
                }
            }
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }
    throw Erreur("La transaction n'existe pas\n");

}

void TransactionManager::afficherTransactions(){
    try{
        if(trans.size()!=0){
            cout<<"-----Date-----|-----Reference-----|-----Memo-----|-----Marque-----\n";
            for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
                cout<<(*it)->date<<"       |";
                cout<<(*it)->reference<<"                  |";
                cout<<(*it)->memo<<"         |";
                cout<<(*it)->marque<<"\n";
            }
        }
        else{
            throw Erreur("Il n'y a pas des transactions\n");
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }
}

void TransactionManager::afficherTransactionsCompte(CompteReel& c){
    string nom = c.getNom();
    int i=0;
    try{
        if(trans.size()!=0){
            cout<<"-----Date-----|-----Reference-----|-----Memo-----|-----Marque-----\n";
            for(std::vector<Transaction*>::iterator it1=trans.begin();it1!=trans.end();it1++){
                for(std::vector<Operation*>::iterator it2=(*it1)->operations.begin();it2!=(*it1)->operations.end();it2++){
                    if((*it2)->getCompte().getNom()==nom){
                        if(i==0){
                            cout<<(*it1)->date<<"       |";
                            cout<<(*it1)->reference<<"                  |";
                            cout<<(*it1)->memo<<"         |";
                            cout<<(*it1)->marque<<"\n";
                        }
                        i=1;
                    }
                }
                i=0;
            }
        }
        else{
            throw Erreur("Il n'y a pas des transactions\n");
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }
}
*/

void TransactionManager::afficherTransactionsQT(QTableWidget* t){
    try{
        if(trans.size()!=0){
            for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){

                t->insertRow(t->rowCount());//inserta una fila al final
                t->setItem(t->rowCount() - 1, 0, new QTableWidgetItem (QString::fromStdString((*it)->getMemo())));
                t->setItem(t->rowCount() - 1, 1, new QTableWidgetItem (QString::number((*it)->getReference())));
                //t->setItem(t->rowCount() - 1, 2, new QTableWidgetItem (date.toString(Qt::ISODate)));
                t->setItem(t->rowCount() - 1, 3, new QTableWidgetItem (QString::number((*it)->getMarque())));
            }
        }
        else{
            throw Erreur("Il n'y a pas des transactions\n");
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }
}

void TransactionManager::afficherSurQcombobox(QComboBox* c){
    try{
        if(trans.size()!=0){
            for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
                c->addItem(QString::number((*it)->getReference()));
            }
        }
        else{
            throw Erreur("Il n'y a pas des transactions\n");
        }
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }
}
