#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <fstream>
using namespace std;
class Account
{
public:
    Account();
    Account(ifstream &fin);
    std::string Name;
    int actualBalance;
    string number;
    int OverdraftLimit;
    friend ifstream &operator>> (ifstream &fin, Account &a);
    friend ofstream &operator<< (ofstream &fout, const Account &a);
};

#endif // ACCOUNT_H
