#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int tc, n, q, query, count ;
  string temp ;
  cin>> tc ;
  while(tc--)
  {
    cin>> n ;
    vector<int> l(n), h(n) ;
    vector<string> name(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> name[i] >> l[i] >> h[i] ;
    cin>> q ;
    while(q--)
    {
      cin>> query ;
      count=0 ;
      for(int i=0 ; i<n ; i++)
      {
        if(l[i]<=query && query<=h[i])
        {
          count++ ;
          temp=name[i] ;
          if(count>1) break ;
        }
      }
      if(count==0 || count>1) cout<< "UNDETERMINED" << endl ;
      else cout<< temp << endl ;
    }
    if(tc!=0) cout<< endl ;
  }
 return 0 ;
}
