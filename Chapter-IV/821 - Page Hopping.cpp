#include <bits/stdc++.h>
using namespace std ;

int T, from, to, n, temp, sum, total ;
vector<vector<int> > adj ;

void bfs(int start)
  {
    sum=0 ;
    vector<int> distance(101, -1) ;
    queue<int> discovered ;
    discovered.push(start) ;
    distance[start]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj[temp].size() ; i++)
          {
            if(distance[adj[temp][i]]==-1)
              {
                distance[adj[temp][i]]=distance[temp]+1 ;
                discovered.push(adj[temp][i]) ;
                sum+=distance[adj[temp][i]] ;
              }
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  T=1 ;
  while(cin>> from >> to)
  {
    total=0 ;
    if(from==0 && to==0) break ;
    adj.clear() ;
    adj.resize(101) ;
    adj[from].push_back(to) ;
    set<int> count ;
    count.insert(from) ;
    count.insert(to) ;
    while(cin>>from >> to)
      {
        if(from==0 && to==0) break ;
        count.insert(from) ; count.insert(to) ;
        adj[from].push_back(to) ;
      }
    n=count.size() ;
    set<int>::iterator it ;
    it=count.begin() ;
    while(it!=count.end())
      {
          bfs(*it) ;
          total+=sum ;
          it++ ;
      }
    float ans=(float)total/((n-1)*n) ;
    cout<< "Case "<< T++ <<": average length between pages = "<< fixed << setprecision(3) << ans <<" clicks" << endl ;
   }
   return 0 ;
 }
