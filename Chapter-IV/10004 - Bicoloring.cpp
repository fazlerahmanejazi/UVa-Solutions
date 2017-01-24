#include <bits/stdc++.h>
using namespace std ;

int n, m, temp1, temp2 ;
vector<bool> visit;
vector<int> color ;
vector<vector<int>> l ;
bool check ;

void dfs(int t, int p)
{
  if(!check) return ;
  visit[t]=true ;
  color[t]=p ;
  for(int i=0 ; i<l[t].size() ; i++)
      {
        if(visit[l[t][i]]!=true) dfs(l[t][i], 1-p) ;
        else if(color[t]==color[l[t][i]]) { check=false ; return ; }
      }
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n && n!=0)
  {
    cin>> m ;
    color.assign(n, 0) ;
    visit.assign(n, false) ;
    l.clear() ;
    l.resize(n) ;
    for(int i=0 ; i<m ; i++)
    {
      cin>> temp1 >> temp2 ;
      l[temp1].push_back(temp2) ;
      //l[temp2].push_back(temp1) ; No need of this.
    }
    check=true ;
    for(int i=0 ; i<n ; i++)
      if(visit[i]==false)
       dfs(i, 0) ;
    if(check) cout<< "BICOLORABLE." << endl ;
    else cout<< "NOT BICOLORABLE." << endl ;
  }
    return 0 ;
}
