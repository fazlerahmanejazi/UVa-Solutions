  #include <bits/stdc++.h>
  using namespace std ;

  int n, m, num, T ;
  int  temp1, temp2 ;
  vector<bool> visit;
  vector<int> topo ;
  vector<vector<int> > adj ;

  void dfs_topo(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
        if(visit[adj[t][i]]!=true)
           dfs_topo(adj[t][i]) ;
    topo.push_back(t) ;
  }

  void dfs(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
        if(visit[adj[t][i]]!=true)
           dfs(adj[t][i]) ;
  }

  int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    while(T--)
    {
      cin>> n >> m ;
      adj.clear() ;
      adj.resize(n+1) ;
      visit.assign(n+1, false) ;
      topo.clear() ;
      for(int i=0 ; i<m ; i++)
        {
          cin>> temp1 >> temp2 ;
          adj[temp1].push_back(temp2) ;
        }

      for(int i=1 ; i<=n ; i++)
       if(visit[i]==false)
         dfs_topo(i) ;
      visit.assign(n+1, false) ;
      num=0 ;
      for(int i=0 ; i<n ; i++)
       {
         if(visit[topo[i]]==false)
            {
              num++ ;
              dfs(topo[i]) ;
            }
       }
       cout<< num << endl ;
     }
     return 0 ;
   }
