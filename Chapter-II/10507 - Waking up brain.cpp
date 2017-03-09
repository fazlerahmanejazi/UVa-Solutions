#include <bits/stdc++.h>
using namespace std ;

int n, m, c, years, wake, check ;
char a, b ;
vector<vector<int > > adj ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> m)
    {
      map<char, int> cnc ;
      adj.clear() ;
      adj.resize(27) ;
      vector<bool> awake(27, false) ;
      c=1 ;
      years=0 ;
      for(int i=0 ; i<3 ; i++)
        {
          cin>> a ;
          if(!cnc[a]) { cnc[a]=c++ ; }
          awake[cnc[a]]=true ;
        }
      check=n-3 ;
      for(int i=0 ; i<m ; i++)
        {
          cin>> a >> b ;
          if(!cnc[a]) { cnc[a]=c++ ; }
          if(!cnc[b]) { cnc[b]=c++ ; }
          adj[cnc[a]].push_back(cnc[b]) ;
          adj[cnc[b]].push_back(cnc[a]) ;
        }
        for(int k=0 ; k<n ; k++)
          {
            vector<int> temp ;
            for(int i=1 ; i<=n ; i++)
              {
                if(!awake[i])
                  {
                    wake=0 ;
                    for(int j=0 ; j<adj[i].size() ; j++)
                      if(awake[adj[i][j]]) wake++ ;
                    if(wake>=3)
                      temp.push_back(i) ;
                  }
              }
            if(temp.empty()) break ;
            for(int i=0 ; i<temp.size() ; i++)
              {
                awake[temp[i]]=true ;
                check-- ;
              }
            years++ ;
          }
        if(!check) cout<< "WAKE UP IN, " << years << ", YEARS" << endl ;
        else cout<< "THIS BRAIN NEVER WAKES UP" << endl ;

    }
  return 0 ;
}
