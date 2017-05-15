#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    int n ;
    vector<bool> prime(1000010, true) ;
    for (int p=2 ; p*p<=1000000 ; p++)
      if (prime[p])
        for (int i=p*2 ; i<=1000000 ; i+=p)
          prime[i]=false ;
    while(cin>>n && n)
      {
        for(int i=3 ; i<=(n+1)/2 ; i=i+2)
          if(prime[i] && prime[n-i])
            {
              cout<< n << " = " << i << " + " << n-i << endl ;
              break ;
            }
      }
  }
