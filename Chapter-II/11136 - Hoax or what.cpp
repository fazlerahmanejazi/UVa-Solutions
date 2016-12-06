
#include <bits/stdc++.h>
using namespace std ;
int main()
{ multiset<long int> a ;
   multiset<long int>::iterator x,y;
  long int d, n, p, temp ;
  while(cin>> d && d!=0)
  { p=0 ; a.clear() ;
    while(d--)
    { cin>> n ;
      while(n--)
      {
        cin>> temp ;
        a.insert(temp) ;
      }
      x=a.begin() ;
      y=a.end() ;
      y-- ;
      p = p + *y - *x ;
      a.erase(x) ; a.erase(y) ;

    }
    cout<< p << endl ;
  }
  return 0 ;
}
