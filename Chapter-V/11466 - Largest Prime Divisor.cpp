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

lli n, ans, c ;
vlli fac, prime ;
vb isprime(10000001, true) ;

void sieve()
  {
    isprime[1]=false ;
    for (lli p=2 ; p<=10000000 ; p++)
      if (isprime[p])
        for (lli i=p*p ; i<=10000000 ; i+=p)
          isprime[i]=false ;
    for(int i=2 ; i<=10000000 ; i++)
      if(isprime[i]) prime.pb(i) ;
  }

void solve(lli n)
  {
    fac.clear() ;
    ans=-INF ;
    c=0 ;
    for(lli i=0 ; i<prime.size() && prime[i]*prime[i]<=n ; i++)
      {
        if(n%prime[i]==0)
          {
            c++ ;
            ans=max(ans, prime[i]) ;
          }
        while(n%prime[i]==0)
          n/=prime[i] ;
      }
    if(n>ans)
      {
        ans=n ;
        c++ ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    sieve() ;
    while(cin>> n && n)
      {
        solve(abs(n)) ;
        if(c==1) cout<< -1 << endl ;
        else cout<< ans << endl ;
      }
  }
