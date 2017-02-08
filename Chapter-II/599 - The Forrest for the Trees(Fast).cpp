#include <bits/stdc++.h>
using namespace std ;

int T, tree, acorn, q ;
string temp ;
vector<bool> visit, avail ;
vector<vector<int> > adj ;

void dfs(int t)
{
  visit[t]=true ;
  q++ ;
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
    tree=0 ;
    acorn=0 ;
    visit.clear() ;
    visit.assign(27, false) ;
    avail.assign(27, false) ;
    adj.clear() ;
    adj.resize(27) ;
    vector<int> l ;
    while(1)
      {
        cin>> temp ;
        if(temp[0]=='*') break ;
        adj[temp[1]-64].push_back(temp[3]-64) ;
        adj[temp[3]-64].push_back(temp[1]-64) ;
      }
    cin>> temp ;
    for(int i=0 ; i<temp.length() ; i=i+2)
        {
          l.push_back(temp[i]-64) ;
          avail[temp[i]-64]=1 ;
        }

    for(int i=0 ; i<l.size() ; i++)
      {
        if(visit[l[i]]!=true && avail[l[i]]==1)
          {
            q=0 ;
            dfs(l[i]) ;
            if(q>1) tree++ ;
            else acorn++ ;
          }
      }
    cout<< "There are "<< tree << " tree(s) and "<< acorn <<" acorn(s)." << endl ;
  }
  return 0 ;
}
