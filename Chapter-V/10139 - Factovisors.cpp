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

lli legendre(lli n, lli p)
  {
    lli ans=0 ;
    for(lli i=p ; i<=n ; i*=p)
      ans+=n/i ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, m, x, num ;
    bool check ;
    while(cin>> n >> m)
      {
        check=true ;
        num=m ;
        for(lli i=2 ; i<=sqrt(m) ; i++)
          if(m%i==0)
            {
              x=0 ;
              while(m%i==0)
                {
                  x++ ;
                  m/=i ;
                }
              if(x>legendre(n, i))
                {
                  check=false ;
                  break ;
                }
            }
        if(m!=1 && legendre(n, m)<1) check=false ;
        if(check) cout<< num << " divides " << n << "!" << endl ;
        else cout<< num << " does not divide " << n << "!" << endl ;
      }
  }
