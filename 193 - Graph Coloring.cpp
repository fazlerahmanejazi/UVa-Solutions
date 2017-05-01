#include <bits/stdc++.h>
using namespace std ;

int T, n, m, c, u, v, b, maxM ;
vector<int> color, ans ;
vector<vector<int>> adj ;
bool check ;

void backtrack(int t)
  {
    if(t==n+1)
      {
        b=0 ;
        for(int i=1 ; i<=n ; i++)
          if(color[i]==0) b++ ;
        if(b>maxM)
          {
            ans.clear() ;
            for(int i=1 ; i<=n ; i++)
              if(color[i]==0)
                ans.push_back(i) ;
            maxM=b ;
          }
        return ;
      }
    check=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
        if(color[adj[t][i]]==0)
          check=false ;
    if(check)
      {
        color[t]=0 ;
        backtrack(t+1) ;
        color[t]=1 ;
      }
    color[t]=1 ;
    backtrack(t+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m ;
        maxM=0 ;
        adj.clear() ;
        adj.resize(n+1) ;
        color.assign(n+1, 1) ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> v ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
          }
        backtrack(1) ;
        cout<< ans.size() << endl ;
        for(int i=0 ; i<ans.size()-1 ; i++)
          cout<< ans[i] << " " ;
        cout<< ans[ans.size()-1] << endl ;
      }
  }
