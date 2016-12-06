#include <bits/stdc++.h>
using namespace std ;

int main()
{ int n, d, r, sum ;

  while(cin>> n >> d >> r && n!=0)
  { sum=0 ;
    vector <int> D(n), E(n) ;
    for(int i=0 ; i<n ; i++)
    cin>> D[i] ;
    for(int i=0 ; i<n ; i++)
    cin>> E[i] ;
    sort(D.begin(), D.end()) ;
    sort(E.begin(), E.end()) ;
    reverse(E.begin(), E.end()) ;
    for(int i=0 ; i<n ; i++)
    {
      D[i]=D[i]+E[i] ;
      if(D[i]-d>0)
      {
        sum = sum + (D[i]-d)*r ;
      }
    }
    cout<< sum << endl ;
  }
  return 0 ;
}
