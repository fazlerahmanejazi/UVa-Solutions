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

lli n, x, f ;
string s ;
vlli fac, prime ;
vb isprime(32767+1, true) ;
map<lli, lli> cnt ;

void sieve()
  {
    isprime[1]=false ;
    for (lli p=2 ; p<=32767 ; p++)
      if (isprime[p])
        {
          for (lli i=p*p ; i<=32767 ; i+=p)
            isprime[i]=false ;
          prime.pb(p) ;
        }
  }

void solve(lli n)
  {
    cnt.clear() ;
    fac.clear() ;
    for(lli i=0 ; i<prime.size() && prime[i]*prime[i]<=n ; i++)
      {
        if(n%prime[i]==0)
          fac.pb(prime[i]) ;
        while(n%prime[i]==0)
          {
            n/=prime[i] ;
            cnt[prime[i]]++ ;
          }
      }
    if(n!=1)
      {
        fac.pb(n) ;
        cnt[n]++ ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    sieve() ;
    while(1)
      {
        getline(cin, s) ;
        if(s=="0") break ;
        istringstream is(s) ;
        n=1 ;
        while(is>> x >> f)
          n*=(lli)pow(x, f) ;
        n-- ;
        solve(n) ;
        sort(all(fac)) ;
        reverse(all(fac)) ;
        for(int i=0 ; i<fac.size() ; i++)
          if(i!=fac.size()-1) cout<< fac[i] << " " << cnt[fac[i]] << " " ;
          else cout<< fac[i] << " " << cnt[fac[i]] ;
        cout<< endl ;
      }
  }
