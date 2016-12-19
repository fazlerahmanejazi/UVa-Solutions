#include <bits/stdc++.h>
using namespace std ;

int tc, n, rod, temp, check ;
vector<int> bars ;

void solve(int index, int sum)
{
  if(sum==rod)
  {
    check=1 ;
    return ;
  }
  if(index>=n && sum!=rod)
  {
    check=0 ;
    return ;
  }
  for(int i=index ; i<n ; i++)
  {
    if(bars[i]+sum<=rod)
     { sum=sum+bars[i] ;
       solve(i+1, sum) ;
       if(check==1) return ;
       sum=sum-bars[i] ;
     }
  }
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> tc ;
  while(tc--)
  { bars.clear() ;
    cin>> rod>> n ;
    for(int i=0 ; i<n ; i++)
     {
       cin>> temp ;
       bars.push_back(temp) ;
     }
     check=0 ;
    solve(0,0) ;
    if(check==1) cout<< "YES" << endl ;
    else cout<< "NO" << endl ;
  }
  return 0 ;
}
