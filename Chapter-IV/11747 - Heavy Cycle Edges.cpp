#include <bits/stdc++.h>
using namespace std ;

int N, n, m, a, b, w ;
pair<int,int> temp ;
pair<pair<int,int>,int> TEMP ;
vector<bool> visit;
int parent ;
vector<vector< pair<pair<int, int>, int> > > adj ;
vector<vector<int> > check ;
priority_queue<pair<pair<int, int>, int> > pq ;

void process(int v)
  {
    visit[v]=1 ;
    for(int i=0 ; i<adj[v].size() ; i++)
      {
        temp=adj[v][i].first ;
        w=temp.first ;
        if(!visit[w])
          {
            temp=adj[v][i].first ;
            a=temp.second ;
            temp.second=-temp.first ;
            temp.first=-a ;
            TEMP.first=temp ;
            TEMP.second=v ;
            pq.push(TEMP) ;
          }
      }
  }

void prim()
  {
    while(!pq.empty())
      {
        TEMP=pq.top() ;
        pq.pop() ;
        temp=TEMP.first ;
        b=-temp.second ;
        parent=TEMP.second ;
        if(!visit[b])
          {
            check[b][parent]=-1 ;
            check[parent][b]=-1 ;
            process(b) ;
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> m)
    {
      if(n==0 && m==0) break ;
      N=0 ;
      set<int> ans ;
      adj.clear() ;
      check.clear() ;
      vector<int> dump(n+1, -1) ;
      for(int i=0 ; i<=n ; i++)
        check.push_back(dump) ;
      adj.resize(n+1) ;
      visit.assign(n+1, true) ;
      for(int i=0 ; i<m ; i++)
        {
          cin>> a >> b >> w ;
          if(check[a][b]!=-1)
            {
              if(w>check[a][b]) ans.insert(w) ;
              else { ans.insert(check[a][b]) ; }
            }
          check[a][b]=w ;
          check[b][a]=w;
          temp=make_pair(b,w) ;
          TEMP=make_pair(temp, a) ;
          adj[a].push_back(TEMP) ;
          temp=make_pair(a,w) ;
          TEMP=make_pair(temp, b) ;
          adj[b].push_back(TEMP) ;
          visit[a]=false ; visit[b]=false ;
        }
      for(int i=0 ; i<n ; i++)
        {
          if(!visit[i])
           {
             parent=i ;
             process(i) ;
             prim() ;
           }
        }

      for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
          if(check[i][j]>=0)
            	ans.insert(check[i][j]) ;
      if(ans.empty()) cout<< "forest" << endl ;
      else
        {
          set<int>::iterator it ;
          it=ans.begin() ;
          cout<< *it ;
          it++ ;
          while(it!=ans.end())
            {
              cout<< " " << *it ;
              it++ ;
            }
          cout<< endl ;
        }
    }
  return 0 ;
}
