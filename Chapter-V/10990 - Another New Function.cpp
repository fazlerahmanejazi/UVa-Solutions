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

vi phi(2000001), depthphi(2000001) ;
vlli sum(2000001) ;

void modified_sieve()
  {
    for (int i=1 ; i<=2000000 ; i++)
      phi[i]=i ;
    for (int p=2 ; p<=2000000 ; p++)
      if (phi[p]==p)
        for (int i=p ; i<=2000000 ; i+=p)
          phi[i]-=phi[i]/p ;
  }

void preprocess()
  {
    modified_sieve() ;
    depthphi[1]=sum[1]=0 ;
    for(int i=2 ; i<=2000000 ; i++)
      {
        depthphi[i]=1+depthphi[phi[i]];
        sum[i]=sum[i-1]+depthphi[i] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, n, m ;
    preprocess() ;
    cin>> T ;
    while(T--)
      {
        cin>> m >> n ;
        cout<< sum[n]-sum[m-1] << endl ;
      }
  }
