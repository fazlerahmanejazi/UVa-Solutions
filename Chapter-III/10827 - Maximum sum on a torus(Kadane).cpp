#include <bits/stdc++.h>
using namespace std ;


int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, M=-1, sum, T, temp, m, ans ;
  cin>> T ;
while(T--)
{  while(cin>> n)
 {
   m=n ;
   n=2*n ;
   M=-1 ;
   vector< vector<int> > seq(n+1, vector<int>(m+1)), dp(n+1, vector<int>(m+1)) ;
   for(int i=1 ; i<=m ; i++)
    for(int j=0 ; j<m ; j++)
     { cin>> temp ;
       seq[i][j]=temp ;
       seq[i+m][j]=temp ;
     }
   for(int i=0 ; i<=n ; i++)
    dp[0][i]=0 ;

   for(int i=1 ; i<=n ; i++)
     {for(int j=0 ; j<m ; j++)
        {dp[i][j]=seq[i][j]+dp[i-1][j] ;
        //cout<< dp[i][j] << " " ;
        }
        //cout<<endl ;
     }

   ans=-10000 ;
    for(int i=1 ; i<=n ; i++)
      {
        for(int j=max(0,i-m) ; j<i ; j++)
        {

          for(int l=0 ; l <m ; l++)
          {
          	sum=0 ; M=-10000 ;
          	for(int k = l; k < l+m; k++)
           {
               temp=dp[i][k]-dp[j][k] ;
               sum += temp;
               if(sum > M) M = sum;
               if(sum < 0) sum = 0;
           }
           if(M>ans) ans=M ;
          }

        }
      }


      int t = 0;
             for(int i=1;i<=2*n; i++) {
                 for(int j=i;j<=min(i+n-1, 2*n);j++) {
                     int smax=0, smin=0, ssum=0, tmax=0, tmin=0;
                     for(int k=1;k<=n; k++)
                         ssum += T[j][k] - T[i-1][k];

                     for(int k=1;k<=n; k++) {
                         int a = T[j][k] - T[i-1][k];
                         smax += a;
                         smin += a;

                         tmax = max(tmax, smax);
                         tmin = min(tmin, smin);

                         if (smax < 0) smax = 0;
                         if (smin > 0) smin = 0;
                     }
                     t = max(t, max(tmax, ssum-tmin));
                 }
             }

   cout<< ans << endl;
 }
 }
  return 0 ;
}
