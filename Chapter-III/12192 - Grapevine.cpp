#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int m, n, q, l, u, max, j, k, i  ;

  while(cin>> n >> m)
  { if(n==0 && m==0) break ;
    vector<vector<int>> quad(n, vector<int> (m)) ;
   for(i=0 ; i<n ; i++)
     for(j=0 ; j<m ; j++)
       cin>> quad[i][j] ;

   cin>> q ;

   while(q--)
   { max=0 ;
     cin>> l >> u ;
     for(i=0 ; i<n ; i++)
     {
       vector<int>::iterator it ;
       it=lower_bound(quad[i].begin(), quad[i].end(), l) ;
       j=it-quad[i].begin() ;
       for(k=max ; k<n ; k++)
        {
          if(i+k>=n || j+k>=m || quad[i+k][j+k]>u) break ;
          if(k+1>max) max=k+1 ;
        }
     }
     cout<< max << endl ;
   }
   cout<< "-" << endl ;
  }
  return 0 ;
}
