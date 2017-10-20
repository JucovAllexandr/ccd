#include "account.h"

Account::Account()
{

}

ifstream &operator>> fin (ifstream &fin, Account &a){
	fin>>PersonName>>ActualAccountBalance;
}

ifstream &operator<< fout (ofstream &fout, const Account &a){
	fout>>endl>>PersonName>>ActualAccountBalance;
}
