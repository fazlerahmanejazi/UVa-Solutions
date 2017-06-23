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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    string s ;
    char c ;
    int m=131071, ans, l, p ;
    vi P(1, 1) ;
    for(int i=1 ; i<=10000 ; i++)
      P.pb((P[i-1]*2)%m) ;
    while(cin>> c)
      {
        s="" ; s+=c ;
        while(cin>> c)
          if(c=='#') break ;
          else s+=c ;
        l=s.length() ;
        ans=p=0 ;
        for(int i=l-1 ; i>=0 ; i--, p++)
          if(s[i]=='1')
            ans=(ans+P[p])%m ;
        ans=ans%m ;
        if(ans==0) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
