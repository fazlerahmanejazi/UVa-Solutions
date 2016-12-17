#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int tc, n, ans ;
  cin>> tc ;
  while(tc--)
  { cin>> n ;
    ans= 0 ;
    vector<int> seq(n) ;
    vector<int> inc(n, 1) ;
    vector<int> dec(n, 1) ;
    for(int i=0 ; i<n ; i++)
      cin>> seq[i] ;

    for(int i=n-1 ; i>=0 ; i--)
    {
      for(int j=i+1 ; j<n ; j++)
      {
        if(seq[i]<seq[j] && inc[i]<inc[j]+1) inc[i]=inc[j]+1 ;
        if(seq[i]>seq[j] && dec[i]<dec[j]+1) dec[i]=dec[j]+1 ;
      }
       ans=max(ans, inc[i]+dec[i]-1) ;
    }
    cout<< ans << endl ;
  }
  return 0 ;
}
