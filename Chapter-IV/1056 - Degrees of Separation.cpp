#include <bits/stdc++.h>
using namespace std ;

int T, n, m, c, ans, temp ;
vector<vector<int> > adj ;
string a, b ;

int bfs(int start)
  {
    int M=0 ;
    vector<int> distance(n+1, -1) ;
    queue<int> discovered ;
    discovered.push(start) ;
    distance[start]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj[temp].size() ; i++)
          {
            if(distance[adj[temp][i]]==-1)
              {
                distance[adj[temp][i]]=distance[temp]+1 ;
                discovered.push(adj[temp][i]) ;
                if(M<distance[adj[temp][i]]) M=distance[adj[temp][i]] ;
              }
          }
      }
    for(int i=1 ; i<=n ; i++)
        if(distance[i]==-1)
          return -1 ;
    return M ;
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  T=1 ;
  while(cin>> n >> m)
    {
      if(n==0) break ;
      adj.clear() ;
      adj.resize(n+1) ;
      c=1 ;
      ans=0 ;
      map<string, int> cnc ;
      for(int i=0 ; i<m ; i++)
        {
          cin>> a >> b ;
          if(cnc[a]==0) { cnc[a]=c ; c++ ; }
          if(cnc[b]==0) { cnc[b]=c ; c++ ; }
          adj[cnc[a]].push_back(cnc[b]) ;
          adj[cnc[b]].push_back(cnc[a]) ;
        }
      for(int i=1 ; i<=n ; i++)
        {
          temp=bfs(i) ;
          if(temp==-1)
            {
              ans=-1 ;
              break ;
            }
          else ans=max(temp, ans) ;
        }
      if(ans==-1) cout<< "Network "<< T++ <<": DISCONNECTED" << endl ;
      else cout<< "Network "<< T++ << ": " << ans << endl ;
      cout<< endl ;
    }
   return 0 ;
 }
