#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int tc, n, sum ;
  cin>> tc ;
  while(cin>>n &&tc--)
  { sum=0 ;
    vector<int> sales(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> sales[i] ;
        for(int j=0 ; j<i ; j++)
         if(sales[i]>=sales[j])
              sum++ ;
      }
    cout<< sum << endl ;
   }
  return 0 ;
}
