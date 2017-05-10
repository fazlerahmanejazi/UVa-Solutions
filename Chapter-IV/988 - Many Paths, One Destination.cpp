#include <bits/stdc++.h>
using namespace std ;

int n, m, temp, ways ;
vector<bool> visit;
vector<int> ans ;
vector<int> life ;
vector<vector<int> > adj ;
bool blank ;

void dfs(int t)
{
  visit[t]=true ;
  for(int i=0 ; i<adj[t].size() ; i++)
      if(visit[adj[t][i]]!=true)
         dfs(adj[t][i]) ;
  ans.push_back(t) ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  blank=false ;
  while(cin>> n)
  {
    ways=0 ;
    if(blank) cout<< endl ;
    ans.clear() ;
    adj.clear() ;
    life.clear() ;
    visit.assign(n+1, false) ;
    adj.resize(n+1) ;
    life.resize(n+1) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> m ;
        for(int j=0 ; j<m ; j++)
          {
            cin>> temp ;
            adj[i].push_back(temp) ;
          }
      }
    for(int i=0 ; i<n ; i++)
        if(!visit[i])
            dfs(i) ;
    for(int i=ans.size()-1 ; i>=0 ; i--)
      life[ans.size()-1-i]=ans[i] ;
    ans.assign(n+1, 0) ;
    ans[0]=1 ;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<adj[life[i]].size() ; j++)
          ans[adj[life[i]][j]]+=ans[life[i]] ;
    for(int i=0 ; i<n ; i++)
      if(adj[i].size()==0)
        ways+=ans[i] ;
    cout<< ways << endl ;
    blank=true ;
  }
    return 0 ;
}
