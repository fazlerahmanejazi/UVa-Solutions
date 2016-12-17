#include <bits/stdc++.h>
using namespace std ;

int main()
{ ios_base::sync_with_stdio (false) ;
  int N, K ;
  while(cin>> N >> K, N, K)
  { int ways[101][101] ;
    memset(ways, 0, sizeof(ways));
    for(int i=0 ; i<=N ; i++)
     ways[1][i]=1 ;

    for(int i=2 ; i<=K ; i++)
     {
       for(int j=0 ; j<=N ; j++)
       {
         for(int l=0 ; l<=j ; l++)
           ways[i][j]=(ways[i][j]+ways[i-1][j-l])%1000000 ;
       }
     }
    cout<< ways[K][N] << endl ;
  }
return 0 ;
}
