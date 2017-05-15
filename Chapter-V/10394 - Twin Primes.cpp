#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    int n, a, b ;
    vector<pair<int, int>> ans ;
    vector<bool> prime(20000010, true) ;
    for (int p=2 ; p*p<=20000000 ; p++)
      if (prime[p])
        for (int i=p*2 ; i<=20000000 ; i+=p)
          prime[i]=false ;
    for(int i=3 ; i<=20000000 ; i=i+2)
        if(prime[i] && prime[i+2]) ans.push_back(make_pair(i, i+2)) ;
        else if(!prime[i+2]) i=i+2 ;
    while(cin>>n)
      {
        a=ans[n-1].first ; b=ans[n-1].second ;
        cout<< "(" << a << ", " << b << ")" << endl ;
      }
  }
