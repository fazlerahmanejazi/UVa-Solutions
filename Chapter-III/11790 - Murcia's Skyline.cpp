#include <bits/stdc++.h>
using namespace std ;

int main()
{ios_base::sync_with_stdio (false) ;
  int tc, n, minc, mdec ;
  cin>>tc ;
  for(int T=1 ; T<=tc ; T++)
  {
    cin>> n ;
    vector<int> h(n), w(n), dp(n,1), inc(n), dec(n) ;
    for(int i=0 ; i<n ; i++)
      cin>>h[i] ;
    for(int i=0 ; i<n ; i++)
      { cin>>w[i] ; inc[i]=w[i] ; dec[i]=w[i] ; }
    minc=inc[0] ; mdec=dec[0] ;
    for(int i=1 ; i<n ; i++)
    {
      for(int j=0 ; j<i ; j++)
      {
        if(h[i]>h[j] && w[i]+inc[j]>inc[i])
          {
            inc[i]=w[i]+inc[j] ;
          }
        if(h[i]<h[j] && w[i]+dec[j]>dec[i])
          {
            dec[i]=w[i]+dec[j] ;
          }
      }
      if(inc[i]>minc) minc=inc[i] ;
      if(dec[i]>mdec) mdec=dec[i] ;

    }
    if(minc>=mdec) cout<< "Case "<< T <<". Increasing ("<< minc <<"). Decreasing ("<< mdec << ")." << endl ;
    else cout<< "Case "<< T <<". Decreasing ("<< mdec <<"). Increasing ("<< minc << ")." << endl ;
  }
  return 0 ;
}
