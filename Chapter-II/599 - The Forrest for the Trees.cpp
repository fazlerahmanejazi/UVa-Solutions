#include <bits/stdc++.h>
using namespace std ;

int T, num, tree, acorn, q ;
string temp ;
vector<bool> visit ;
vector<vector<int> > adj ;
map<char,int> avail ;

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
    num=1 ;
    visit.clear() ;
    visit.assign(27, false) ;
    avail.clear() ;
    adj.clear() ;
    adj.resize(27) ;
    map<char, int> cnc ;
    while(1)
      {
        cin>> temp ;
        if(temp[0]=='*') break ;
        if(avail[temp[1]]==0)
        {
          cnc[temp[1]]=num ;
          avail[temp[1]]=1 ;
          num++ ;
        }
        if(avail[temp[3]]==0)
        {
          cnc[temp[3]]=num ;
          avail[temp[3]]=1 ;
          num++ ;
        }
        adj[cnc[temp[1]]].push_back(cnc[temp[3]]) ;
        adj[cnc[temp[3]]].push_back(cnc[temp[1]]) ;
      }
    cin>> temp ;
    for(int i=0 ; i<temp.length() ; i=i+2)
      {
        if(avail[temp[i]]==0)
          {
            avail[temp[i]]=1 ;
            cnc[temp[i]]=num ;
            num++ ;
          }
      }
    for(int i=1 ; i<num ; i++)
      {
        if(visit[i]!=true)
          {
            q=0 ;
            dfs(i) ;
            if(q>1) tree++ ;
            else acorn++ ;
          }
      }
    cout<< "There are "<< tree << " tree(s) and "<< acorn <<" acorn(s)." << endl ;
  }
  return 0 ;
}
