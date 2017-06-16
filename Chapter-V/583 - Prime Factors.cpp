#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

lli n ;
vlli fac ;

void generate(lli n)
  {
    fac.clear() ;
    while(n%2==0)
      {
        fac.pb(2) ;
        n/=2 ;
      }
    for(int i=3 ; i<=sqrt(n) ; i+=2)
      while(n%i==0)
        {
          fac.pb(i) ;
          n/=i ;
        }
    if(n>2) fac.pb(n) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    while(cin>> n && n)
      {
        generate(abs(n)) ;
        cout<< n << " = " ;
        if(n<0) cout<< -1 << " x " ;
        for(int i=0 ; i<fac.size() ; i++)
          if(i!=fac.size()-1) cout<< fac[i] << " x " ;
          else cout<< fac[i] << endl ;
      }
  }
