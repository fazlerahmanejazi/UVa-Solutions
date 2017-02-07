#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int T, x, a, b, c ;
  cin>> T ;
  for(int tc=1 ; tc<=T ; tc++)
    {
      cin>> x ;
      vector<vector<int> > wind(11, vector<int>(x/100 )) ;
      vector<vector<int> > dp(11, vector<int>(x/100 )) ;
      for(int i=9 ; i>=0 ; i--)
          for(int j=0 ; j<x/100 ; j++)
            {
              cin>> wind[i][j] ;
              dp[i][j]=10000 ;
            }

      for(int j=0 ; j<x/100 ; j++) { dp[10][j]=10000 ; wind[10][j]=0 ; }
      dp[0][0]=0 ;
      for(int j=0 ; j<x/100 ; j++)
        {
          for(int i=1 ; j+i<x/100 && i<10 ; i++)
            {
              a=dp[i+1][i+j-1]+20-wind[i+1][i+j-1] ;
              b=dp[i][i+j-1]+30-wind[i][i+j-1] ;
              c=dp[i-1][i+j-1]+60-wind[i-1][i+j-1] ;
              dp[i][i+j]=min({a,b,c}) ;
            }
        }
        for(int i=9 ; i>=0 ; i--)
          {
            for(int j=0 ; j<x/100 ; j++)
              {
                cout<< dp[i][j] << " " ;
              }
              cout<< endl ;
          }

      cout<< dp[1][x/100-1]+20-wind[1][x/100-1]   ;
      cout<< endl << endl ;
    }
  return 0 ;
  }
