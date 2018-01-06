#include <iostream>
#include <transaction.h>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

bool cmp(const Transaction &a, const Transaction &b)
{
    return a.time<b.time;
}

vector<Account>::iterator find(string f, vector<Account> &v)
{
    vector<Account> t;
    t.push_back(Account());
    vector<Account>::iterator it = v.begin();
    while(it != v.end())
    {
        if((*it).number == f)
            return it;
        it++;
    }
    return t.begin();
}


int main()
{


    ifstream in ("level2/level2-2.txt");
    ofstream out ("out.txt");
    int n;
    vector<Transaction> t;
    vector<Account> vt;
    in>>n;
    int n2=n;
    regex r("CAT\\d{2}[a-zA-Z]{10}");
    for(int i=0;i<n;i++){
        Account tmp(in);
        if(regex_match(tmp.number,r)){
            int a[256]={0};
            for(int j=5;j<tmp.number.length();j++)
            a[tmp.number[j]]++;
            int k=0; while (a['a'+k]==a['A'+k] && k!=30) k++;
            int s=312;
            for(int j=5;j<tmp.number.length();j++)
                s+=tmp.number[j];
            //cout<<s<<endl;
            if (k==30 && 98-s%97 == (tmp.number[3]-'0')*10+(tmp.number[4]-'0'))
            vt.push_back(tmp);
            else n2--;
        }
    }
    int m;
    in >> m;

    for(int i=0;i<m;i++)
        t.push_back(Transaction(in));
    sort(t.begin(),t.end(),cmp);

    for(int i=0;i<m;i++){
    t[i].addTransaction(find(t[i].from,vt),find(t[i].to,vt),t[i].amount,t[i].time);
    }

        //t.addTransaction(find(t.from,vt),find(t.to,vt),t.amount,t.time);


    out<<n2<<endl;
    for(int i=0;i<n2;i++)
        out<<vt[i];
    return 0;
}

