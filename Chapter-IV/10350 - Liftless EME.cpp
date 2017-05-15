#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
int n, m, ans, dist[120][16][16], dp[120][16] ;
string s ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> s)
    {
      cin>> n >> m ;
      for (int i=0 ; i<n-1; i++)
          for (int j=0 ; j<m ; j++)
              for (int k=0 ; k<m ; k++)
                cin>> dist[i][j][k] ;
      memset(dp, 100, sizeof(dp)) ;
      memset(dp[0], 0, sizeof(dp[0])) ;
      for (int i=0 ; i<n-1; i++)
          for (int j=0 ; j<m ; j++)
              for (int k=0 ; k<m ; k++)
                dp[i+1][k] = min(dp[i+1][k], dp[i][j]+dist[i][j][k]);
      ans=inf ;
      for(int i=0 ; i<m ; i++)
        ans=min(ans, dp[n-1][i]) ;
      ans+=2*n-2 ;
      cout<< s << endl ;
      cout<< ans << endl ;
    }
    return 0 ;
}
