#include "transaction.h"

Transaction::Transaction()
{
    count=0;
}

void Transaction::addTransaction(Account from, Account to, int amount, long long time)
{
    from.actualBalance -= amount;
    to.actualBalance += amount;
    count++;
}

