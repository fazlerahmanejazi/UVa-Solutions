#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    int n, edges, ans, temp ;
    while(cin>>n)
      {
        edges=1<<n ;
        ans=0 ;
        vector<int> weights(edges+1), sum(edges+1, 0) ;
        for(int i=0 ; i<edges ; i++)
          cin>> weights[i] ;
        for(int i=0 ; i<edges ; i++)
          for(int j=0 ; j<n ; j++)
            sum[i]+=weights[i^(1<<j)] ;
        for(int i=0 ; i<edges ; i++)
          for(int j=0 ; j<n ; j++)
            ans=max(ans, sum[i]+sum[i^(1<<j)]) ;
        cout<< ans << endl ;
      }
    return 0 ;
  }
