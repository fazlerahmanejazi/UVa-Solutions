#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long int n, m, maxm, l, r, q, mid, count ;
  vector<long int> vessel(n+1), temp(n+1) ;
  while(cin>>n>>m)
  { maxm=0 ;
    for(int i=0 ; i<n ; i++)
      {
         cin>> vessel[i] ;
         if(maxm<vessel[i]) maxm=vessel[i] ;
      }
    l=maxm ; r=1000000010 ;
    while(l!=r)
    {
      q=0 ;
      mid=(l+r)/2 ;
      count=1 ;
      for(int i=0 ; i<n ; i++)
      {
        if(q+vessel[i]>mid) {count++ ; q=vessel[i] ;}
        else q+=vessel[i] ;
      }
      if(count>m) l=mid+1 ;
      else r=mid ;
    }
    cout<< l << endl ;
  }
  return 0;
}
