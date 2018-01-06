#include "account.h"


Account::Account()
{
    OverdraftLimit=-1;
}

Account::Account(ifstream &fin)
{
    fin>>Name>>number>>actualBalance>>OverdraftLimit;
}

ifstream &operator>>  (ifstream &fin, Account &a){
    fin>>a.Name>>a.actualBalance;
}

ofstream &operator<<  (ofstream &fout, const Account &a){
    fout<<a.Name<<" "<<a.actualBalance<<endl;
}
