#include <bits/stdc++.h>
using namespace std ;

int n, m, c, d ;
vector<bool> visit;
vector<int> ans ;
vector<vector<int>> l ;

void dfs(int t)
{
  visit[t]=true ;
  for(int i=0 ; i<l[t].size() ; i++)
      if(visit[l[t][i]]!=true)
         dfs(l[t][i]) ;
  ans.push_back(t) ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> m && n!=0)
  {
    ans.clear() ;
    l.clear() ;
    visit.resize(n+1) ;
    for(int i=0 ; i<=n ; i++)
     	visit[i]=false ;
    visit[0]=true ;
    l.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
    {
      cin>> c >> d ;
      l[c].push_back(d) ;
    }
    for(int i=1 ; i<=n ; i++)
      if(visit[i]!=true)
          dfs(i) ;

    for(int i=ans.size()-1 ; i>=0 ; i--)
     {
       cout<< ans[i] ;
       if(i!=0) cout<< " " ;
     }
    cout<< endl ;
  }
    return 0 ;
}
    
