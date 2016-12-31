#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int f, r, n ;
  while(cin>> f && f)
  { n=0 ;
    cin>> r ;
    vector<int> front(f), rear(r) ;
    for(int i=0 ; i<f ; i++)
     cin>> front[i] ;
    for(int i=0 ; i<r ; i++)
     cin>> rear[i] ;
    vector<double> ratio((f*r)+1) ;
    for(int i=0 ; i<f ; i++)
    {
      for(int j=0 ; j<r ; j++)
      {
        ratio[n]=(double)rear[j]/(double)front[i] ;
        n++ ;
      }
    }
    sort(ratio.begin(), ratio.end()) ;
    double m=0 ;
    for(int i=2 ; i<=n ; i++)
    {
      if((ratio[i]/ratio[i-1])>m) m= (ratio[i]/ratio[i-1]) ;
    }
   cout<<  fixed << setprecision(2) << m << endl ;
  }
return 0 ;
}
