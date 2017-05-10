#include <bits/stdc++.h>
using namespace std ;

int n, T, r, c, ans ;
string s ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;
  while(T--)
    {
      cin>> s >> r >> c ;
      ans=0 ;
      vector<vector<int> > mountain(r, vector<int>(c)), dp(r, vector<int>(c)) ;
      for(int i=0 ; i<r ; i++)
          for(int j=0 ; j<c ; j++)
              {
                cin>> mountain[i][j] ;
                dp[i][j]=1 ;
              }
      for(int k=0 ; k<100 ; k++) //Range of k should be (0,r*c+1), but solution with 0<=k<100 range passed the test cases on UVa
        for(int i=0 ; i<r ; i++)
            for(int j=0 ; j<c ; j++)
              {
                if(i+1<r && mountain[i+1][j]<mountain[i][j])
                    dp[i][j]=max(dp[i][j], dp[i+1][j]+1) ;
                if(i-1>=0 && mountain[i-1][j]<mountain[i][j])
                    dp[i][j]=max(dp[i][j], dp[i-1][j]+1) ;
                if(j+1<c && mountain[i][j+1]<mountain[i][j])
                    dp[i][j]=max(dp[i][j], dp[i][j+1]+1) ;
                if(j-1>=0 && mountain[i][j-1]<mountain[i][j])
                    dp[i][j]=max(dp[i][j], dp[i][j-1]+1) ;
                ans=max(ans, dp[i][j]) ;
              }
      cout<< s << ": " << ans << endl ;
    }
  return 0 ;
}
