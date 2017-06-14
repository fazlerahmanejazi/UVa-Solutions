#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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

lli gcd(lli a, lli b) { return b==0 ? a : gcd(b, a % b) ; }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli x, ans ;
    while(cin>> x && x)
      {
        vlli a ;
        a.pb(x) ;
        while(cin>> x && x)
          a.pb(x) ;
        ans=0 ;
        for(int i=1 ; i<a.size() ; i++)
          ans=gcd(ans, abs(a[i]-a[0])) ;
        cout<< ans << endl ;
      }
  }
