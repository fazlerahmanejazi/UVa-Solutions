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

lli x, y, a, b, c, d, c1, c2, n1, n2, X, Y, t, curr ;
plli ans ;

void extendedEuclid(lli a, lli b)
  {
    if(b==0)
      {
        x=1 ; y=0 ;
        d=a ;
        return ;
      }
    extendedEuclid(b, a%b) ;
    lli x1=y ;
    lli y1=x-(a/b)*y ;
    x=x1 ;
    y=y1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    while(cin>> c && c)
      {
        cin>> c1 >> n1 >> c2 >> n2 ;
        extendedEuclid(n1, n2) ;
        if(c%d)
          {
            cout<< "failed" << endl ;
            continue ;
          }
        a=n1 ; b=n2 ;
        x=x*(c/d) ;
        y=y*(c/d) ;
        curr=2*INF ;
        t=ceil((double)(-x*d)/(double)b) ;
        X=x+(b/d)*t ;
        Y=y-(a/d)*t ;
        ans=mp(-1, -1) ;
        if(X>=0 && Y>=0 && X*c1+Y*c2<curr)
          {
            ans=mp(X, Y) ;
            curr=X*c1+Y*c2 ;
          }
        t=floor((double)(y*d)/(double)a) ;
        X=x+(b/d)*t ;
        Y=y-(a/d)*t ;
        if(X>=0 && Y>=0 && X*c1+Y*c2<curr)
          {
            ans=mp(X, Y) ;
            curr=X*c1+Y*c2 ;
          }
        if(ans.fi==-1) cout<< "failed" << endl ;
        else cout<< ans.fi << " " << ans.se << endl ;
      }
  }
