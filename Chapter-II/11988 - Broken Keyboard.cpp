#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    list<char> r;
    list<char>::iterator it;
    while(getline(cin,s))
    {
        r.clear();
        it = r.begin();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
                it = r.begin();
            if(s[i]==']')
                it = r.end();
            if(s[i]!='[' && s[i]!=']')
                r.insert(it,s[i]);
        }
        for(it=r.begin();it!=r.end();it++)
            cout<<*it;
       cout<< endl ;
    }
    return 0;
}
