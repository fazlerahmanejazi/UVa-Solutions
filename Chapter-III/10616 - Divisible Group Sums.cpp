#include <bits/stdc++.h>
using namespace std ;

int n, q, d, m, tc=1, temp ;
vector<int> a ;
int dp[202][12][42] ;

int calc(int index, int count, int sum)
{
  if(count==m)
  {
    if(sum==0) return 1 ;
    return 0 ;
  }
  if(index>=n) return 0 ;

  if(dp[index][count][sum]!=-1) return dp[index][count][sum] ;

  return dp[index][count][sum]=calc(index+1,count+1, (sum+a[index])%d) + calc(index+1, count, sum) ;
}


int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> q)
  {
    if(n==0 && q==0) break ;
    cout<< "SET "<< tc++ <<":" << endl ;
    a.clear() ;
    for(int i=0 ; i<n ; i++)
      {
      	cin>> temp ;
      	a.push_back(temp) ;
      }

    for(int i=1 ; i<=q ; i++)
    {
      memset(dp, -1, sizeof dp) ;
      cin>> d >> m ;
      cout<< "QUERY "<< i <<": " ;
      cout<< calc(0,0,0) << endl ;
    }

  }
return 0 ;
}
