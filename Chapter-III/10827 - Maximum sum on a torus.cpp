#include <bits/stdc++.h>
using namespace std ;


int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, max=-1, sum, T, temp, m ;
  cin>> T ;
while(T--)
{  while(cin>> n)
 {
   m=n ;
   n=2*n ;
   max=-1 ;
   vector< vector<int> > seq(n+1, vector<int>(n+1)), dp(n+1, vector<int>(n+1)) ;
   for(int i=1 ; i<=m ; i++)
    for(int j=1 ; j<=m ; j++)
     { cin>> temp ;
       seq[i][j]=temp ;
       seq[i+m][j]=temp ;
       seq[i][j+m]=temp ;
       seq[i+m][j+m]=temp ;
     }
   for(int i=0 ; i<=n ; i++)
    { dp[i][0]=0 ; dp[0][i]=0 ; }
   for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=n ; j++)
      dp[i][j]=seq[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] ;

   for(int c=1 ; c<=m ; c++)
     for(int d=1 ; d<=m ; d++)
      {
        for(int a=c ; a<=c+m-1 ; a++)
          for(int b=d ; b<=d+m-1 ; b++)
           {
             sum=dp[a][b]-dp[c-1][b]-dp[a][d-1]+dp[c-1][d-1] ;
             if(sum>max) max=sum ;
           }
      }
   cout<< max << endl;
 }
 }
  return 0 ;
}
