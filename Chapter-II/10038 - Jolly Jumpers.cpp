#include <bits/stdc++.h>
using namespace std ;

int main()
{ int n ;
  while(cin>>n)
{ int a[3000], b[3000], c ;
  for(int i=0 ; i<n ; i++)
  { cin>> a[i] ;
    b[i]=0 ;
  }
  b[0]=1 ;
  for(int i=1 ; i<n ; i++)
  { c=abs (a[i]-a[i-1]) ;
    if(c>0 && c<n)
    b[c]=1 ;
  }

  for(int i=0 ; i<n ; i++)
  {
    if(b[i]==0) { cout<< "Not jolly" << endl ; break ; }
    if(i==n-1) {cout<< "Jolly" << endl ;}
  }
}
return 0 ;
}
