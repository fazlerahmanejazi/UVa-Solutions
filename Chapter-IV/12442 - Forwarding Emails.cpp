#include <bits/stdc++.h>
using namespace std ;

int n, a, b, M, curr, ans, T ;
vector<bool> visit, check;
vector<int> temp, cnc ;

void dfs(int t)
{
  visit[t]=true ;
  curr++ ;
  check[t]=false ;
  temp.push_back(t) ;
  if(curr>M)
  {
    M=curr ;
    ans=temp[0] ;
  }
  if(visit[cnc[t]]!=true)
         dfs(cnc[t]) ;
  curr-- ;
  visit[t]=false ;
  temp.pop_back() ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;

  cin>> T ;
  for(int tc=1 ; tc<=T ; tc++)
  {
    cin>> n ;
    visit.assign(n+1, false) ;
    cnc.assign(n+1, -1) ;
    check.assign(n+1, true) ;
    M=-1 ;
    curr=0 ;
    ans=1;
    for(int i=1 ; i<=n ; i++)
    {
      cin>> a >> b ;
      cnc[a]=b ;
    }

    for(int i=1 ; i<=n ; i++)
      if(visit[i]!=true && check[i])
            dfs(i) ;

    cout<< "Case "<<tc<<": "<<ans << endl ;
  }
  return 0 ;
}
