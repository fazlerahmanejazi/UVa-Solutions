#include <bits/stdc++.h>
using namespace std ;

int n, m, a, b, counter, root, child ;
vector<bool> visit ;
pair<int, int> p ;
vector<pair<int, int> > ans ;
vector<vector<int> > adj ;
vector<int> dfs_low, dfs_num, parent, articulation ;

void dfs_articulation(int t)
  {
    visit[t]=true ;
    dfs_low[t]=dfs_num[t]=counter++ ;
    for(int i=0 ; i<adj[t].size() ; i++)
      {
        if(!visit[adj[t][i]])
          	 {
               parent[adj[t][i]]=t ;
               if(t==root) child++ ;
               dfs_articulation(adj[t][i]) ;
               if(dfs_low[adj[t][i]]>=dfs_num[t]) articulation[t]++ ;
               dfs_low[t]=min(dfs_low[t], dfs_low[adj[t][i]]) ;
             }
        else if(adj[t][i]!=parent[t]) dfs_low[t]=min(dfs_low[t], dfs_low[adj[t][i]]) ;
      }
  }

void dfs(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
        if(!visit[adj[t][i]])
        	 dfs(adj[t][i]) ;
  }

  bool compare(const pair<int,int> &a,const pair<int,int> &b)
    {
        if(a.second!=b.second) return a.second>b.second ;
        else return a.first<b.first;
  	}

int main()
  {
    ios_base::sync_with_stdio (false) ;
    while(cin>> n >> m)
    {
    	if(n==0) break ;
      adj.clear() ;
      ans.clear() ;
      adj.resize(n+1) ;
      dfs_low.clear() ;
      dfs_num.clear() ;
      parent.clear() ;
      parent.resize(n+1) ;
      dfs_low.resize(n+1) ;
      dfs_num.resize(n+1) ;
      articulation.assign(n+1, 0) ;
      visit.assign(n+1, false) ;
      while(cin>> a >> b)
        {
          if(a==-1) break ;
          adj[a].push_back(b) ;
          adj[b].push_back(a) ;
        }

      root=0 ;
      child=0 ;
      dfs_articulation(0) ;
      if(child>1) articulation[0]=1 ;
      else articulation[0]=0 ;
      for(int i=0 ; i<n ; i++)
        {
          articulation[i]++ ;
          p=make_pair(i, articulation[i]) ;
          ans.push_back(p) ;

        }
      sort(ans.begin(), ans.end(), compare) ;
      for(int i=0 ; i<m ; i++)
          cout<< ans[i].first << " " << ans[i].second << endl ;
      cout<< endl ;
    }
    return 0 ;
  }
