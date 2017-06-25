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
using plli = pair<lli, lli> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int x, y, a, b, d ;

void extendedEuclid(int a, int b)
  {
    if(b==0)
      {
        x=1 ; y=0 ;
        d=a ;
        return ;
      }
    extendedEuclid(b, a%b) ;
    int x1=y ;
    int y1=x-(a/b)*y ;
    x=x1 ;
    y=y1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    while(cin>> a >> b)
      {
        extendedEuclid(a, b) ;
        cout<< x << " " << y << " " << d << endl ;
      }
  }
