#include <bits/stdc++.h>
using namespace std ;

int T, n, dp[102][102], x, y ;
long long int ans ;
char board[102][102] ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n ;
        ans=0 ;
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            {
              cin>> board[i][j] ;
              if(board[i][j]=='W') { x=i ; y=j ; }
              dp[i][j]=0 ;
            }
        dp[x][y]=1 ;
        for(int i=x-1 ; i>=0 ; i--)
          {
            for(int j=0 ; j<n ; j++)
              {
                if(board[i][j]=='.')
                  {
                    if(i+1<n && j+1<n) dp[i][j]+=dp[i+1][j+1] ;
                    if(i+1<n && j-1>=0) dp[i][j]+=dp[i+1][j-1] ;
                    dp[i][j]=dp[i][j]%1000007 ;
                  }
                else if(i+1<n && j+1<n && i-1>=0 && j-1>=0)
                  {
                	  if(board[i-1][j-1]=='.') dp[i-1][j-1]+=dp[i+1][j+1] ;
                    if(board[i-1][j+1]=='.') dp[i-1][j+1]+=dp[i+1][j-1] ;
                    dp[i-1][j-1]=dp[i-1][j-1]%1000007 ;
                    dp[i-1][j+1]=dp[i-1][j+1]%1000007 ;
                  }
              }
          }
        for(int i=0 ; i<n ; i++)
          ans=ans+dp[0][i] ;
        cout<< "Case " << tc << ": " << ans%1000007 << endl ;
      }
    return 0 ;
  }
