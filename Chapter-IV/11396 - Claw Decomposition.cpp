#include <bits/stdc++.h>
using namespace std ;

vector<vector<int> > adj ;
bool check ;
vector<int> color ;
int n, a, b ;

void dfs(int t, int temp)
{
  if(check==false) return ;
  color[t]=temp ;
  for(int i=0 ; i<adj[t].size() ; i++)
  {
    if(color[adj[t][i]]==-1) dfs(adj[t][i], 1-temp) ;
    else if(color[adj[t][i]]==color[t]) { check=false ; return ; }
  }
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>>n && n)
  {
    adj.clear() ;
    color.clear() ;
    adj.resize(n+1) ;
    color.assign(n+1, -1) ;
    while(cin>> a >> b && a)
    {
      adj[a].push_back(b) ;
      adj[b].push_back(a) ;
    }
    check=true ;
    dfs(1, 1) ;
    if(check) cout<< "YES" <<endl ;
    else cout<< "NO" <<endl ;
  }
  return 0;
}
