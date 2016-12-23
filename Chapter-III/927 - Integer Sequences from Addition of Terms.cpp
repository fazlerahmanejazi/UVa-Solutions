#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long int tc, degree, k, d, temp ;
  long long int ans ;
  cin>> tc ;
  while(tc--)
  {
  	cin>> degree ;
    vector<long int> coef(degree+1) ;
    for(int i=0 ; i<=degree ; i++)
      cin>> coef[i] ;
    cin>> d ;
    cin>> k ;

    long int n=0 ;
    while(++n)
    {
      temp=d*n*(n+1) ;
      temp=temp/2 ;
      if(k<=temp)
         break ;
    }

    ans=0 ;
    for(int i=0 ; i<=degree ; i++)
     ans= ans + coef[i]*pow(n,i) ;

    cout<< ans << endl ;
  }
  return 0 ;
}
