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

vi period={0, 60, 300, 1500, 15000} ;

int solve(int a, int b, int n, int m)
  {
    int p=period[m] ;
    m=pow(10, m) ;
    a=a%m ; b=b%m ;
    vi seq(p+1) ;
    seq[0]=a ; seq[1]=b ;
    for(int i=2 ; i<=p ; i++)
      seq[i]=(seq[i-1]+seq[i-2])%m ;
    return seq[n%p] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, a, b, n, m ;
    cin>> T ;
    while(T--)
      {
        cin>> a >> b >> n >> m ;
        cout<< solve(a, b, n, m) << endl ;
      }
  }
