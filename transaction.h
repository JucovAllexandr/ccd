#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "account.h"
#include <string>
#include <vector>
using namespace std;
class Transaction
{
public:
    Transaction();
    Transaction(ifstream &fin);
    void addTransaction(vector<Account>::iterator _from, vector<Account>::iterator _to, int amount, long long time);
   friend ifstream &operator>> (ifstream &fin, Transaction &a);
    string from, to;
    int amount;
    long long time;

};

#endif // TRANSACTION_H
