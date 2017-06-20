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

vi prime ;
vb isprime(32000, true) ;
map<lli, lli> dp ;

void sieve()
  {
    isprime[1]=false ;
    for (int p=2 ; p*p<=32000 ; p++)
      if (isprime[p])
        for (int i=p*p ; i<=32000 ; i+=p)
          isprime[i]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=32000 ; i+=2)
      if(isprime[i]) prime.pb(i) ;
  }

lli solve(lli x)
  {
    lli y=x ;
    if(dp[x]!=0) return dp[x] ;
    lli ans=1 ;
    for(int i=0 ; i<prime.size() && prime[i]<=sqrt(x) ; i++)
      {
        lli cnt=0 ;
        while(x%prime[i]==0)
          {
            cnt++ ;
            x/=prime[i] ;
          }
        ans*=(cnt+1) ;
      }
    if(x!=1) ans*=2 ; //when x is a prime number
    dp[y]=ans ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    lli l, u, ans, curr, num ;
    sieve() ;
    cin>> T ;
    while(T--)
      {
        ans=-1 ;
        cin>> l >> u ;
        for(lli i=l ; i<=u ; i++)
          {
            curr=solve(i) ;
            if(curr>ans)
              {
                ans=curr ;
                num=i ;
              }
          }
        cout<< "Between " << l << " and " << u << ", " << num << " has a maximum of " << ans << " divisors." << endl ;
      }
  }
