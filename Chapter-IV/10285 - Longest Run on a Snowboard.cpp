#include <bits/stdc++.h>
using namespace std ;

int n, T, r, c, ans, mountain[101][101], dp[101][101] ;
string s ;

int backtrack(int i, int j)
  {
    if(dp[i][j]!=-1) return dp[i][j] ;
    if(i+1<r && mountain[i+1][j]<mountain[i][j])
        dp[i][j]=max(dp[i][j], backtrack(i+1, j)+1) ;
    if(i-1>=0 && mountain[i-1][j]<mountain[i][j])
        dp[i][j]=max(dp[i][j], backtrack(i-1, j)+1) ;
    if(j+1<c && mountain[i][j+1]<mountain[i][j])
        dp[i][j]=max(dp[i][j], backtrack(i, j+1)+1) ;
    if(j-1>=0 && mountain[i][j-1]<mountain[i][j])
        dp[i][j]=max(dp[i][j], backtrack(i, j-1)+1) ;
    return dp[i][j] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    while(T--)
      {
        cin>> s >> r >> c ;
        ans=0 ;
        for(int i=0 ; i<r ; i++)
            for(int j=0 ; j<c ; j++)
                {
                  cin>> mountain[i][j] ;
                  dp[i][j]=-1 ;
                }
        for(int i=0 ; i<r ; i++)
            for(int j=0 ; j<c ; j++)
                ans=max(ans, backtrack(i, j)) ;
        cout<< s << ": " << ans+2 << endl ;
      }
    return 0 ;
  }
