#include <bits/stdc++.h>
using namespace std ;

int main()
{ int T, N, c ;
  long int X ;
  cin>> T ;
  while(T--)
  {
    while(cin>> N)
    { c=1 ;
      vector<long int> a(N) ;
      for(int i=0 ; i<N ; i++)
      cin>> a[i] ;
    /*  X=a[N-1]-1 ;
      for(int i=N-2 ; i>=0; i--)
      {
        if(X>=a[i])
        {
          c++ ;
          X=X-a[i] ;
          if(X>=a[i]) i++ ;
        }
      } */
      X=a[0] ;
      for(int i=1;i<N-1;i++)
      {
           if (X+a[i]<a[i+1])
           {
               X+=a[i];
               c++;
           }
       }
       c++ ;
      cout<< c << endl ;
    }
  }
  return 0 ;
}
