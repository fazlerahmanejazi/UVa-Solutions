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
vlli fac, prime ;
vb isprime(47001, true) ;

void sieve()
  {
    isprime[1]=false ;
    for (lli p=2 ; p<=47000 ; p++)
      if (isprime[p])
        for (lli i=p*p ; i<=47000 ; i+=p)
          isprime[i]=false ;
    for(int i=2 ; i<=47000 ; i++)
      if(isprime[i]) prime.pb(i) ;
  }

void solve(lli n)
  {
    fac.clear() ;
    lli idx=0, x=prime[0] ;
    while(x*x<=n)
      {
        while(n%x==0)
          {
            n/=x ;
            fac.pb(x) ;
          }
        x=prime[++idx] ;
      }
    if(n!=1) fac.pb(n) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    sieve() ;
    while(cin>> n && n)
      {
        solve(abs(n)) ;
        cout<< n << " = " ;
        if(n<0) cout<< -1 << " x " ;
        for(int i=0 ; i<fac.size() ; i++)
          if(i!=fac.size()-1) cout<< fac[i] << " x " ;
          else cout<< fac[i] << endl ;
      }
  }
