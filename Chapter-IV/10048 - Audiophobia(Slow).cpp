#include <bits/stdc++.h>
using namespace std ;

int n, c, s, q, a, b, w, ans, start, finish, T ;
pair<int, int> temp ;
vector<bool> visit;
vector<vector<pair<int, int> > > adj ;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq ;

void process(int v)
  {
    visit[v]=1 ;
    if(v==finish)
        {
        	for(int i=0 ; i<=n ; i++)
            	visit[i]=true ;
            return ;
        }
    for(int i=0 ; i<adj[v].size() ; i++)
      {
        w=adj[v][i].first ;
        if(!visit[w])
          {
            temp.first=adj[v][i].second ;
            temp.second=adj[v][i].first ;
            pq.push(temp) ;
          }
      }
  }

void prim()
  {
    while(!pq.empty())
      {
        temp=pq.top() ;
        pq.pop() ;
        a=temp.first ;
        b=temp.second ;
        if(!visit[b])
          {
            if(ans<a) ans=a ;
            process(b) ;
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  T=1 ;
  while(cin>> c >> s >> q)
    {
     n=c ;
      if(c==0 && s==0) break ;
      if(T!=1) cout<< endl ;
      adj.clear() ;
      adj.resize(n+1) ;
      for(int i=0 ; i<s ; i++)
        {
          cin>> a >> b >> w ;
          temp=make_pair(b, w) ;
          adj[a].push_back(temp) ;
          temp=make_pair(a, w) ;
          adj[b].push_back(temp) ;
        }
      cout<< "Case #" << T++ << endl ;
      for(int i=0 ; i<q ; i++)
        {
          cin>> start >> finish ;
          ans=0 ;
          visit.assign(n+1, false) ;
          process(start) ;
          prim() ;
          if(visit[finish]) cout<< ans << endl ;
          else cout<< "no path" << endl ;
        }
    }
  return 0 ;
}
