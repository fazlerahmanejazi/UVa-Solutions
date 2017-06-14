#include <bits/stdc++.h>
using namespace std ;

int gcd(int a, int b)
  {
  	if(a%b==0) return b ;
  	return gcd(b, a%b) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    int T, x ;
    string s ;
    cin>> T ;
    getline(cin, s) ;
    while(T--)
      {
        vector<int> a ;
        getline(cin, s) ;
        istringstream is(s) ;
        while(is>>x)
          a.push_back(x) ;
        x=0 ;
        for(int i=0 ; i<a.size() ; i++)
          for(int j=i+1 ; j<a.size() ; j++)
            x=max(x, gcd(a[i], a[j])) ;
        cout<< x << endl ;
      }
  }
