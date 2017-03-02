#include <bits/stdc++.h>
using namespace std ;

int T, temp, E, n, day, M, c ;
vector<vector<int> > adj ;
vector<int> days ;
map<int, int> query ;
void bfs(int start)
  {
    queue<int> discovered ;
    discovered.push(start) ;
    days[start]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj[temp].size() ; i++)
          {
            if(days[adj[temp][i]]==-1)
              {
                days[adj[temp][i]]=days[temp]+1 ;
                discovered.push(adj[temp][i]) ;
                if(days[adj[temp][i]]>M) M=days[adj[temp][i]] ;
                query[days[adj[temp][i]]]++ ;
              }
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> E ;
  adj.clear() ;
  adj.resize(E+1) ;
  for(int i=0 ; i<E ; i++)
    {
      cin>> n ;
      for(int j=0 ; j<n ; j++)
        {
          cin>> temp ;
          adj[i].push_back(temp) ;
        }
    }
  cin>> T ;
  while(cin>> temp && T--)
  {
    days.clear() ;
    query.clear() ;
    days.assign(E+1, -1) ;
    M=0 ;
    day=0 ;
    c=0 ;
    bfs(temp) ;
    for(int i=0 ; i<=M ; i++)
      {
        if(query[i]>c)
          {
            day=i ;
            c=query[i] ;
          }
      }
    if(c) cout<< c << " " << day << endl ;
    else cout<< 0 << endl ;
  }
   return 0 ;
 }
 
