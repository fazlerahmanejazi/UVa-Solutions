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

map<int, int> S ;

int solve(int n)
  {
    int ans=0 ;
    for(int i=1 ; i<=sqrt(n) ; i++)
      if(n%i==0)
        if(n/i==i) ans+=i ;
        else ans+=(n/i)+i ;
    return ans ;
  }

void preprocess()
  {
    for(int i=1 ; i<=1000 ; i++)
      S[solve(i)]=i ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, tc=1 ; ;
    preprocess() ;
    while(cin>> n && n)
      {
        cout<< "Case " << tc++ << ": " ;
        if(S[n]) cout<< S[n] << endl ;
        else cout<< -1 << endl ;
      }
  }
