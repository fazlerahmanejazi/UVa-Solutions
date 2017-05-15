#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
int T, l, u , r, ans ;
vector<int> buttons ;
vector<int> dist ;

int bfs()
  {
    queue<int> discovered ;
    int temp, curr ;
    dist[l]=0 ;
    discovered.push(l) ;
    while(!discovered.empty())
      {
        temp=discovered.front() ; discovered.pop() ;
        if(temp==u)
            return dist[u] ;
        for(int i=0 ; i<r ; i++)
          {
            curr=(temp+buttons[i])%10000 ;
            if(dist[curr]==inf)
              {
                dist[curr]=dist[temp]+1 ;
                discovered.push(curr) ;
              }
          }
      }
    return -1 ;
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  T=1 ;
  while(cin>> l >> u >> r)
    {
      if(l==0 && u==0 && r==0) break ;
      dist.assign(10010, inf) ;
      buttons.clear() ;
      buttons.resize(r+1) ;
      for(int i=0 ; i<r ; i++)
        cin>> buttons[i] ;
      ans=bfs() ;
      if(ans==-1) cout<< "Case " << T++ << ": Permanently Locked" << endl ;
      else cout<<  "Case " << T++ << ": " << ans << endl ;
    }
    return 0 ;
}
  
