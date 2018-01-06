#include "transaction.h"
Transaction::Transaction()
{

}

Transaction::Transaction(ifstream &fin)
{
    fin>>from>>to>>amount>>time;
}

void Transaction::addTransaction(vector<Account>::iterator _from, vector<Account>::iterator _to, int _amount, long long _time)
{
    if( (*_from).OverdraftLimit < 0 || (*_to).OverdraftLimit < 0) return;
    if((*_from).actualBalance - amount < (-(*_from).OverdraftLimit)) return;

    (*_from).actualBalance -= amount;
    (*_to).actualBalance += amount;
}



 ifstream &operator>> (ifstream &fin, Transaction &a){
    fin>>a.from>>a.to>>a.amount>>a.time;
}
