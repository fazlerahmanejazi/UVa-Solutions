#include <bits/stdc++.h>
using namespace std ;

int main()
{ long long int n, s, d ;
  cin>> n ;
  while(n--)
  {
    cin>> s >> d ;
  if(s<d) cout<< "impossible" << endl ;
  else
  {
    if(s%2==0)
    {
      if(d%2==0) cout<<(d+s)/2 << " " << (s-d)/2 << endl ;
      else cout<< "impossible" << endl ;
    }
    else
    {
      if(d%2==0) cout<< "impossible" << endl ;
      else cout<<(d+s)/2 << " " << (s-d)/2 << endl ;
    }
  }
} return 0 ;
}
