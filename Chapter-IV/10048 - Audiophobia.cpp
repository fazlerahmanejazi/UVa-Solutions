#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
int n, c, s, q, a, b, w, start, finish, T ;
vector<vector<int> > adj(110, vector<int>(110)) ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  T=1 ;
  while(cin>> c >> s >> q)
  {
    n=c ;
    if(c==0 && s==0) break ;
    if(T!=1) cout<< endl ;
    for(int i=0 ; i<110 ; i++)
      for(int j=0 ; j<110 ; j++)
        adj[i][j]=inf ;
    for(int i=0 ; i<s ; i++)
      {
        cin>> a >> b >> w ;
        adj[a][b]=adj[b][a]=w ;
      }
    for(int k=1 ; k<=n ; k++)
      for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
          adj[i][j]=adj[j][i]=min(adj[i][j], max(adj[i][k], adj[k][j])) ;
    cout<< "Case #" << T++ << endl ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> start >> finish ;
        if(adj[start][finish]==inf) cout<< "no path" << endl ;
        else cout<< adj[start][finish] << endl ;
      }
  }
   return 0 ;
 }
