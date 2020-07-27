#include "TransactionManager.h"
#include <sstream>

class Erreur;

using namespace std;

TransactionManager TransactionManager::instance = TransactionManager();

TransactionManager& TransactionManager::getInstance()
{
    return instance;
}

ostream& operator<<(ostream& f, const Operation& op);

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
        throw Erreur("ERREUR: La transaction n'existe pas\n");
    }catch(exception& e){
        cout<<"message="<<e.what()<<"\n";
    }

    
}

void TransactionManager::ajouterTransaction (const TIME::Date& d,const int r, const string& m, vector<Operation*>o){
    try{
        for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
            if((*it)->getReference() == r){
                throw Erreur("ERREUR: La transaction existe déjà\n");
            }
        }
    
    Transaction* new_trans = new Transaction(d,r,m,o);
    if ( new_trans->Validation_Vector_Operations(o) ) {
        trans.push_back(new_trans);
    }
    else  throw Erreur("ERREUR: Transaction non valide\n");
    }catch(exception& e){
        cout<<e.what()<<"\n";
        return;
    }
}

void TransactionManager::supprimerTransaction (int r){
    try{
        for(std::vector<Transaction*>::iterator it=trans.begin(); it!=trans.end(); it++){
            if( (*it)->getReference() == r ){
            	if((*it)->getMarque()==true) throw Erreur("ERREUR: Impossible de supprimer une transaction rapprochée");
                (*it)->Reverse_Transaction( (*it)->getOperation() ) ;
                (*it)->~Transaction() ;
                delete (*it) ;
                trans.erase(it );
                return;
            }
        }
    }catch(exception& e){
        cout<<e.what()<<"\n";
  	return;
    }
    throw Erreur("ERREUR: La transaction n'existe pas\n");
}

void TransactionManager::editerTransaction (int r){
    int i;
    try{
        for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
            if((*it)->getReference() == r){
            
            	if((*it)->getMarque()==true) throw Erreur("ERREUR: Impossible de modifier une transaction rapprochée");
            	cin>>i;
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
                    (*it)->Modification_Vector_Operations(*it);
                    break;
                }
                }
                return;
            }
        }
        }
        catch(exception& e){
        cout<<e.what()<<"\n";
  	return;
    }
        throw Erreur("ERREUR: La transaction n'existe pas");
}

void TransactionManager::afficherTransactions(){
	int nb;

    try{
        if(trans.size()!=0){
        stringstream s_trans;
        stringstream s_date;
        stringstream s_memo;
        stringstream s_marque;
            for(std::vector<Transaction*>::iterator it=trans.begin();it!=trans.end();it++){
            	nb=(*it)->operations.size();
            
            	s_trans<<" TRANSACTION "<<(*it)->reference<<" ";
            	s_memo<<" Intitulé: "<<(*it)->memo<<" ";
            	s_date<<" Date: "<<(*it)->date<<" ";
            	if( (*it)->marque) s_marque<<" Rapproché: OUI ";
                else s_marque<<" Rapproché: NON ";
		
		cout<<"┌";
		
            	for (int i=0;i<s_trans.str().size();i++) cout<<"─";
            	cout<<"┬";
            	for (int i=0;i<s_memo.str().size()-1;i++) cout<<"─";
            	cout<<"┬";
            	for (int i=0;i<s_date.str().size();i++) cout<<"─";
            	cout<<"┬";
            	for (int i=0;i<s_marque.str().size()-1;i++) cout<<"─";
            	cout<<"┐\n";
            	
            	
                cout<<"│"<<s_trans.str();
                cout<<"│"<<s_memo.str();
                cout<<"│"<<s_date.str();
                cout<<"│"<<s_marque.str()<<"│\n";
                
                cout<<"└";
                for (int i=0;i<s_trans.str().size();i++) cout<<"─";
            	cout<<"┴";
            	for (int i=0;i<s_memo.str().size()-1;i++) cout<<"─";
            	cout<<"┴";
            	for (int i=0;i<s_date.str().size();i++) cout<<"─";
            	cout<<"┴";
            	for (int i=0;i<s_marque.str().size()-1;i++) cout<<"─";
            	cout<<"┘\n";

		cout<<"\nLISTE DES OPERATIONS:\n\n";
		
		cout<<"┌──────────────────────────────┬──────────────┬──────────────┐\n";
		cout<<"│            COMPTE            │     Débit    │    Crédit    │\n";
		cout<<"├──────────────────────────────┼──────────────┼──────────────┤\n";

                for(std::vector<Operation*>::iterator it2=(*it)->operations.begin();it2!=(*it)->operations.end();it2++){
                        cout<<(*(*it2));
                        if (nb>1)cout<<"├──────────────────────────────┼──────────────┼──────────────┤\n";
                        nb--;
                }
                cout<<"└──────────────────────────────┴──────────────┴──────────────┘\n\n";
                s_trans.str("");
                s_date.str("");
                s_memo.str("");
                s_marque.str("");
                cout<<"════════════════════════════════════════════════════════════════════════════════\n\n";
            }
        }
        else{
            throw Erreur("ERREUR: Il n'y a pas des transactions\n");
        }
    }catch(exception& e){
        cout<<e.what()<<"\n";
    }
}

void TransactionManager::afficherTransactionsCompte(CompteReel& c){
   	int nb;
	vector<Transaction*> trans_compte = getTransactionsByCompte(c);
    try{
        if(trans.size()!=0){
        stringstream s_trans;
        stringstream s_date;
        stringstream s_memo;
        stringstream s_marque;
            for(std::vector<Transaction*>::iterator it=trans_compte.begin();it!=trans_compte.end();it++){
            	nb=(*it)->operations.size();
            
            	s_trans<<" TRANSACTION "<<(*it)->reference<<" ";
            	s_memo<<" Intitulé: "<<(*it)->memo<<" ";
            	s_date<<" Date: "<<(*it)->date<<" ";
            	if( (*it)->marque) s_marque<<" Rapproché: OUI ";
                else s_marque<<" Rapproché: NON ";
		
		cout<<"┌";
		
            	for (int i=0;i<s_trans.str().size();i++) cout<<"─";
            	cout<<"┬";
            	for (int i=0;i<s_memo.str().size()-1;i++) cout<<"─";
            	cout<<"┬";
            	for (int i=0;i<s_date.str().size();i++) cout<<"─";
            	cout<<"┬";
            	for (int i=0;i<s_marque.str().size()-1;i++) cout<<"─";
            	cout<<"┐\n";
            	
            	
                cout<<"│"<<s_trans.str();
                cout<<"│"<<s_memo.str();
                cout<<"│"<<s_date.str();
                cout<<"│"<<s_marque.str()<<"│\n";
                
                cout<<"└";
                for (int i=0;i<s_trans.str().size();i++) cout<<"─";
            	cout<<"┴";
            	for (int i=0;i<s_memo.str().size()-1;i++) cout<<"─";
            	cout<<"┴";
            	for (int i=0;i<s_date.str().size();i++) cout<<"─";
            	cout<<"┴";
            	for (int i=0;i<s_marque.str().size()-1;i++) cout<<"─";
            	cout<<"┘\n";

		cout<<"\nLISTE DES OPERATIONS:\n\n";
		
		cout<<"┌──────────────────────────────┬──────────────┬──────────────┐\n";
		cout<<"│            COMPTE            │     Débit    │    Crédit    │\n";
		cout<<"├──────────────────────────────┼──────────────┼──────────────┤\n";

                for(std::vector<Operation*>::iterator it2=(*it)->operations.begin();it2!=(*it)->operations.end();it2++){
                        cout<<(*(*it2));
                        if (nb>1)cout<<"├──────────────────────────────┼──────────────┼──────────────┤\n";
                        nb--;
                }
                cout<<"└──────────────────────────────┴──────────────┴──────────────┘\n\n";
                s_trans.str("");
                s_date.str("");
                s_memo.str("");
                s_marque.str("");
                cout<<"═══════════════════════════════════════════════════════════════════════════════════════\n\n";
            }
        }
        else{
            throw Erreur("ERREUR: Il n'y a pas des transactions\n");
        }
    }catch(exception& e){
        cout<<e.what()<<"\n";
    }
}

vector<Transaction*> TransactionManager::getTransactionsByCompte(const CompteReel& c){
	vector<Transaction*> t;

            for(std::vector<Transaction*>::iterator it1=trans.begin();it1!=trans.end();it1++){
                for(std::vector<Operation*>::iterator it2=(*it1)->operations.begin();it2!=(*it1)->operations.end();it2++){
                    if(&((*it2)->getCompte())==&c){
                        t.push_back(*it1);
                        
                    }
                }
            }
        return t;
}

bool TransactionManager::UsageCompte( CompteReel& c ) {
    for ( std::vector<Transaction*>::iterator it1 = trans.begin(); it1 != trans.end(); ++it1 ) {
        for ( unsigned int i = 0 ; i < (*it1)->getOperation().size() ; i++ ) {
            if ( (*it1)->getOperation()[i]->getCompte().getNom() == c.getNom() ) {
            return false ;
            }
        }
    }
    return true ;
}
