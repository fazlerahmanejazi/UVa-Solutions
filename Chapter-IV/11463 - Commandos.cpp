#include <bits/stdc++.h>
using namespace std ;

int T, n, m, temp, a, b, ans ;
vector<vector<int> > adj ;
vector<vector<int> > distances ;

void bfs(int start, int index)
  {
    queue<int> discovered ;
    discovered.push(start) ;
    distances[index][start]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj[temp].size() ; i++)
          {
            if(distances[index][adj[temp][i]]==-1)
              {
                distances[index][adj[temp][i]]=distances[index][temp]+1 ;
                discovered.push(adj[temp][i]) ;
              }
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;
  for(int tc=1 ; tc<=T ; tc++)
  {
    cin>> n >> m ;
    adj.clear() ;
    distances.clear() ;
    vector<int> dump(n+1, -1) ;
    distances.push_back(dump) ; distances.push_back(dump) ;
    adj.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
      }
    cin>> a >> b ;
    bfs(a, 0) ;
    bfs(b, 1) ;
    ans=-1 ;
    for(int i=0 ; i<n ; i++)
      ans=max(distances[0][i]+distances[1][i], ans) ;
    cout<< "Case " << tc << ": " << ans << endl ;
   }
   return 0 ;
 }
