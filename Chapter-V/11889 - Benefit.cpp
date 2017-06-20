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
vb isprime(3200, true) ;

void sieve()
  {
    isprime[1]=false ;
    for (int p=2 ; p*p<=3200 ; p++)
      if (isprime[p])
        for (int i=p*p ; i<=3200 ; i+=p)
          isprime[i]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=3200 ; i+=2)
      if(isprime[i]) prime.pb(i) ;
  }

int solve(int a, int c)
  {
    int b=1 ;
    for(int i=0 ; i<prime.size() && prime[i]<=a && prime[i]<=c ; i++)
      {
        int cntA=0, cntC=0 ;
        while(a%prime[i]==0)
          {
            cntA++ ;
            a/=prime[i] ;
          }
        while(c%prime[i]==0)
          {
            cntC++ ;
            c/=prime[i] ;
          }
        if(cntC>cntA) b*=pow(prime[i], cntC) ;
      }
    if(a==1) b*=c ;
    return b ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, a, b, c ;
    sieve() ;
    cin>> T ;
    while(T--)
      {
        cin>> a >> c ;
        if(c%a==0) cout<< solve(a, c) << endl ;
        else cout<< "NO SOLUTION" << endl ;
      }
  }
