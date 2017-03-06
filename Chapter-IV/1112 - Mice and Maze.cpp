#include <bits/stdc++.h>
using namespace std ;

int T, n, e, t, m, a, b, w, ans ;
vector<vector<pair<int, int> > > adj ;
pair<int, int> temp ;
vector<int> dist ;

void dijkstra(int start)
  {
    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > discovered ;
    temp=make_pair(0, start) ;
    discovered.push(temp) ;
    dist[start]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.top() ;
        discovered.pop() ;
        w=temp.first ;
        a=temp.second ;
        if(dist[a]<w) continue ;
        for(int i=0 ; i<adj[a].size() ; i++)
          {
            temp=adj[a][i] ;
            if(dist[a]+temp.second < dist[temp.first])
              {
                dist[temp.first]=dist[a]+temp.second  ;
                temp=make_pair(dist[temp.first], temp.first) ;
                discovered.push(temp) ;
              }
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;
  while(T--)
  {
    cin>> n >> e >> t >> m ;
    ans=0 ;
    adj.clear() ;
    dist.clear() ;
    dist.assign(n+1, 1000000) ;
    adj.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> b >> w ;
        temp=make_pair(a,w) ;
        adj[b].push_back(temp) ;
      }
    dijkstra(e) ;
    for(int i=1 ; i<=n ; i++)
        if(dist[i]<=t) ans++ ;
    cout<< ans << endl ;
    if(T!=0) cout<< endl ;
   }
   return 0 ;
 }
