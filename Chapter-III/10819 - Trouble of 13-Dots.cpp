#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int m, n, item, index, ans, dp[10300] ;
  while(cin>> m >> n )
  {
    m+=200 ;
    memset(dp, -1, sizeof dp) ;
    dp[0]=0 ;

    for (int i = 0; i < n; i++)
     {
 	     cin>> item >> index ;
 		   for (int j = m - item ; j >= 0; j--)
 		     if (dp[j] != -1)
 		        dp[j + item] = max(dp[j + item], dp[j] + index);
 	   }
    ans=0 ;
    for (int i = 0; i <= m; i++)
		  if (i <= m - 200 || i > 2000)
			  ans = max(ans, dp[i]);

    cout<< ans << endl ;
  }
  return 0 ;
}
