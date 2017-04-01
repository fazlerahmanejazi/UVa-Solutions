#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
int T, n, m, s, t, p, a, b, w, ans ;
vector<vector<pair<int, int> > > adj_t, adj_s ;
pair<int, int> temp ;
vector<int> dist_s, dist_t ;

void dijkstra(int start, vector<vector<pair<int, int> > > adj, vector<int> &dist)
  {
    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > discovered ;
    discovered.push(make_pair(0, start)) ;
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
                discovered.push(make_pair(dist[temp.first], temp.first)) ;
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
    cin>> n >> m >> s >> t >> p ;
    adj_s.clear() ;
    dist_s.assign(n+1, inf) ;
    adj_s.resize(n+1) ;
    adj_t.clear() ;
    dist_t.assign(n+1, inf) ;
    adj_t.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> b >> w ;
        adj_s[a].push_back(make_pair(b,w)) ;
        adj_t[b].push_back(make_pair(a,w)) ;
      }
    dijkstra(s, adj_s, dist_s) ;
    dijkstra(t, adj_t, dist_t) ;
    ans=0 ;
    for(int i=1 ; i<=n ; i++)
      {
        for(int j=0 ; j<adj_s[i].size() ; j++)
          {
            temp=adj_s[i][j] ;
            if(dist_s[i]+temp.second+dist_t[temp.first]<=p)
              ans=max(ans, temp.second) ;
          }
      }
    if(ans) cout<< ans << endl ;
    else cout<< -1 << endl ;
   }
   return 0 ;
 }
