#include <bits/stdc++.h>
using namespace std ;

int n, m, a, b, w, ans, tot ;
pair<int, int> temp ;
vector<bool> visit;
vector<vector<pair<int, int> > > adj ;
priority_queue<pair<int, int> > pq ;

void process(int v)
  {
    visit[v]=1 ;
    for(int i=0 ; i<adj[v].size() ; i++)
      {
        w=adj[v][i].first ;
        if(!visit[w])
          {
            temp.first=-adj[v][i].second ;
            temp.second=-adj[v][i].first ;
            pq.push(temp) ;
          }
      }
  }

int prim()
  {
    while(!pq.empty())
      {
        temp=pq.top() ;
        pq.pop() ;
        a=-temp.first ;
        b=-temp.second ;
        if(!visit[b])
          {
            ans+=a ;
            process(b) ;
          }
      }
    return tot-ans ;
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> m)
    {
      if(n==0 && m==0) break ;
      ans=0 ;
      tot=0 ;
      adj.clear() ;
      adj.resize(n+1) ;
      visit.assign(n+1, false) ;
      for(int i=0 ; i<m ; i++)
        {
          cin>> a >> b >> w ;
          temp=make_pair(b, w) ;
          adj[a].push_back(temp) ;
          temp=make_pair(a, w) ;
          adj[b].push_back(temp) ;
          tot+=w ;
        }
      process(0) ;
      cout<< prim()<< endl ;
    }
  return 0 ;
}
