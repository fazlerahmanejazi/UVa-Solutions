#include <bits/stdc++.h>
using namespace std ;

int main()
{ int N,temp, t, c ;
  while(cin>> N && N!=0)
  { t=0 ; c=0 ;
    while(N--)
    { cin>> temp ;
      if(temp!=0)
      {   if(c==1) cout<< " " ;
          cout<< temp ;
          t=1 ;
          c=1 ;
      }
    }
      if(t==0) cout<< 0 ;
      cout<< endl ;
  }
  return 0 ;
}
