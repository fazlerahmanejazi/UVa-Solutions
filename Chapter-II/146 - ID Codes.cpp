#include <bits/stdc++.h>
using namespace std ;


int main()
{ string s ;
  int l ;
while( cin>> s && s!="#")
  { l=s.length() ;
    if(next_permutation(s.begin(),s.end())) cout<< s << endl ;
    else cout<<"No Successor"<<endl ;
  }
  return 0 ;
}
