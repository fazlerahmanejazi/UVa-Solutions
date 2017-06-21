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

vi mu(1000001, 0), M(1000001, 0) ;
vb prime(1000001, true), squareFree(1000001, true) ;

void sieve()
  {
    prime[1]=false ;
    for (int p=2 ; p<=1000000 ; p++)
      if (prime[p])
        {
          mu[p]=-1 ;
          for (int i=2*p ; i<=1000000 ; i+=p)
            {
              if(i%(p*p)==0) squareFree[i]=false ;
              mu[i]++ ;
              prime[i]=false ;
            }
        }
    for(int i=1 ; i<=1000000 ; i++)
      {
        if(!prime[i])
          if(squareFree[i]) mu[i]=(mu[i]%2)? -1 : 1 ; // mu[1] gets set to 1
          else mu[i]=0 ;
        M[i]=M[i-1]+mu[i] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    sieve() ;
    while(cin>>n && n)
      cout<< setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << endl ;
  }
