#include <bits/stdc++.h>
using namespace std ;

int n, m ;
vector<bool> visit;
vector<int> ans ;
vector<vector<int> > adj ;
vector<int> indegree ;

int main()
{ int tc=1 ;
  ios_base::sync_with_stdio (false) ;
  while(cin>> n)
  {
    ans.clear() ;
    adj.clear() ;
    indegree.clear() ;
    visit.resize(n+1) ;
    adj.resize(n+1) ;
    indegree.resize(n+1) ;
    for(int i=0 ; i<=n ; i++)
     	visit[i]=false ;
    visit[0]=true ;
    map<string, int> cnc ;
    map<int, string> ncn ;
    string temp, temp2 ;
    for(int i=1 ; i<=n ; i++)
    {
      cin>> temp ;
      cnc[temp]=i ;
      ncn[i]=temp ;
    }
    cin>> m ;
    for(int i=0 ; i<m ; i++)
    {
      cin>> temp2 >> temp ;
      adj[cnc[temp2]].push_back(cnc[temp]) ;
      indegree[cnc[temp]]++ ;
    }
    int check=n ;
    while(check)
    {
      for(int i=1 ; i<=n ; i++)
      {
        if(!indegree[i] && !visit[i])
        {
          visit[i]=true ;
          ans.push_back(i) ;
          check-- ;
          for(int j=0 ; j<adj[i].size() ; j++)
           indegree[adj[i][j]]-- ;
          break ;
        }
      }
    }

    cout<< "Case #" <<tc++<< ": Dilbert should drink beverages in this order: " ;
    for(int i=0 ; i<ans.size() ; i++)
     {
       cout<< ncn[ans[i]] ;
       if(i!=n-1) cout<< " " ;
     }
    cout<< "." << endl ;
    cout<< endl ;
  }
    return 0 ;
}
