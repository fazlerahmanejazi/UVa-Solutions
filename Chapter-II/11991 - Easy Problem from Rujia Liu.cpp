#include <bits/stdc++.h>
using namespace std ;

map<int,vector<int> > occur ;
int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, m, temp, k, v ;
  while(cin>>n>>m)
  {
    occur.clear() ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> temp ;
        occur[temp].push_back(i+1) ;
      }
    for(int i=0 ; i<m ; i++)
      {
        cin>> k >> v ;
        if(occur[v].size()>=k) cout<<occur[v][--k] << endl ;
        else cout<< 0 << endl ;
      }
  }
  return 0 ;
}
