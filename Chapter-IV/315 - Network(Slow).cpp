#include <bits/stdc++.h>
using namespace std ;

int n, m, dur, temp, c ;
vector<bool> visit;
string line ;
vector<vector<int> > adj ;

void dfs(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
        if(!visit[adj[t][i]])
        	 dfs(adj[t][i]) ;
  }

bool check()
  {
    for(int i=1 ; i<=n ; i++)
      if(visit[i]==false) return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    while(cin>> n && n)
    {
      c=0 ;
      adj.clear() ;
      adj.resize(n+1) ;
      while(cin>> m && m)
        {
          getline(cin, line) ;
          istringstream iss(line) ;
          while (iss>>temp)
            {
              adj[m].push_back(temp) ;
              adj[temp].push_back(m) ;
            }
        }
      for(int i=1 ; i<=n ; i++)
        {
          visit.assign(n+1, false) ;
          visit[i]=true ;
          if(i==1) dfs(2) ;
          else dfs(i-1) ;
          if(check()) c++ ;
        }
      cout<< c << endl ;
    }
    return 0 ;
  }
