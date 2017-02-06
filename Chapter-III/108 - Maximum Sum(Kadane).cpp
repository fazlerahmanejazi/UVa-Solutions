#include <bits/stdc++.h>
using namespace std ;


int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, max, sum, ans, temp ;
  while(cin>> n)
 {
   max=-1 ;
   vector< vector<int> > seq(n+1, vector<int>(n+1)), dp(n+1, vector<int>(n+1)) ;
   for(int i=1 ; i<=n ; i++)
    for(int j=0 ; j<n ; j++)
     cin>> seq[i][j] ;

   for(int i=0 ; i<n ; i++)
     dp[0][i]=0 ;

   for(int i=1 ; i<=n ; i++)
     for(int j=0 ; j<n ; j++)
       	 dp[i][j]=seq[i][j]+dp[i-1][j] ;

   ans=-10000 ;
   for(int i=1 ; i<=n ; i++)
   {
     for(int j=0 ; j<i ; j++)
     {
       sum=0 ; max=-10000 ;
       for(int k = 0; k < n; k++)
        {
            temp=dp[i][k]-dp[j][k] ;
            sum += temp;
            if(sum > max) max = sum;
            if(sum < 0) sum = 0;
        }
        if(max>ans) ans=max ;
     }
   }

   cout<< ans << endl;
 }
  return 0 ;
}
