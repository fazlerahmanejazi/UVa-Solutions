#include <bits/stdc++.h>
using namespace std ;

int n, m, a, b, c, pos, num;
vector<bool> visit;
bool check ;
vector<vector<int> > adj ;

void dfs(int t)
{
  visit[t]=true ;
  num++ ;
  for(int i=0 ; i<adj[t].size() ; i++)
      if(visit[adj[t][i]]!=true)
         dfs(adj[t][i]) ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> m && n)
  {
    visit.clear() ;
    adj.clear() ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> b >> c ;
        adj[a].push_back(b) ;
        if(c==2) adj[b].push_back(a) ;
      }
    check=true ;
    for(int i=1 ; i<=n ; i++)
    {
      num=0 ;
      visit.assign(n+1, false) ;
      dfs(i) ;
      if(num!=n) { check=false ; break ; }
    }
    if(check) cout<< 1 << endl ;
    else cout<< 0 << endl ;
   }
   return 0 ;
 }
