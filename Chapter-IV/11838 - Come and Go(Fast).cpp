#include <bits/stdc++.h>
using namespace std ;

int n, m, a, b, c, pos, num;
vector<bool> visit;
bool check ;
vector<vector<int> > adj ;
vector<vector<int> > adj_rev ;
vector<int> postvisit ;

void dfs_rev(int t)
{
  visit[t]=true ;
  num++ ;
  for(int i=0 ; i<adj_rev[t].size() ; i++)
      if(visit[adj_rev[t][i]]!=true)
         dfs_rev(adj_rev[t][i]) ;
  postvisit[t]=num++ ;
}

void dfs(int t)
{
  visit[t]=true ;
  num++ ;
  for(int i=0 ; i<adj[t].size() ; i++)
      if(visit[adj[t][i]]!=true)
         dfs(adj[t][i]) ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> m && n)
  {
    visit.clear() ;
    adj.clear() ;
    adj.resize(n+1) ;
    adj_rev.clear() ;
    adj_rev.resize(n+1) ;
    visit.assign(n+1, false) ;
    postvisit.clear() ;
    postvisit.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> b >> c ;
        adj[a].push_back(b) ;
        adj_rev[b].push_back(a) ;
        if(c==2) { adj[b].push_back(a) ; adj_rev[a].push_back(b) ; }
      }
    num=1 ;
    for(int i=1 ; i<=n ; i++)
     if(visit[i]==false)
       dfs_rev(i) ;
    pos=max_element(postvisit.begin(), postvisit.end())-postvisit.begin() ;
    visit.assign(n+1, false) ;
    num=0 ;
    dfs(pos) ;
    if(num==n) cout<< 1 << endl ;
    else cout<< 0 << endl ;
   }
   return 0 ;
 }
