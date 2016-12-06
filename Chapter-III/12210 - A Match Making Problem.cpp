#include <bits/stdc++.h>
using namespace std ;

int main()
{ int B, S, c=1, temp, min ;
  while(cin>>B>>S && B!=0 && S!=0)
  {
      cin>> temp ;
      min=temp ;
      for(int i=0 ; i<B-1 ; i++)
      {
        cin>>temp ;
        if(temp<min) min=temp ;
      }
      for(int i=0 ; i<S ; i++)
        cin>>temp ;
      if(B<=S) cout<< "Case "<< c << ": " << 0 << endl ;
      else cout<< "Case "<< c << ": " << B-S << " " << min << endl ;
      c++ ;
  }
 return 0 ;
}
