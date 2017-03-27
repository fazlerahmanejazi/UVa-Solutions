#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n ;
    while(cin>>n && n)
      {
        int a=0, b=0, pos=1 ;
        for(int i=0 ; i<31 ; i++)
          {
            if(n&(1<<i))
              {
                if(pos%2) a|=(1<<i) ;
                else b|=(1<<i) ;
                pos++ ;
              }
          }
        cout<< a << " " << b << endl ;
      }
    return 0 ;
  }
