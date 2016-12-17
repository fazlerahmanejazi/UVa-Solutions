#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  string s, c ;
  int q, start, end, count, i, j ;
  cin>> s ;
  cin>>q ;
  while(cin>>c && q--)
  { j=0 ; count=0 ;
    for(i=0 ; i<s.length() ; i++)
     {
       if(s[i]==c[j])
       {
         count++ ;
         if(count==1) start=i ;
         if(count==c.length()) { end=i ; break ; }
         j++ ;
       }
     }
    if(count==c.length()) cout<< "Matched " <<start<< " " << end<< endl ;
    else cout<< "Not matched" << endl ;
  }
return 0;
}
