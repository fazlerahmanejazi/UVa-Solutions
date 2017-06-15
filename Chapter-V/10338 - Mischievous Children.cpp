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
		lli n, ans ;
		string s ;
		vlli fac ;
		fac.pb(1) ;
		for(int i=1 ; i<=20 ; i++)
			fac.pb(fac[i-1]*i) ;
		cin>> n ;
		for(int tc=1 ; tc<=n ; tc++)
			{
				map<char, int> cnt ;
				set<char> letters ;
				set<char>::iterator it ;
				cin>> s ;
				ans=fac[s.length()] ;
				for(int i=0 ; i<s.length() ; i++)
					{
						cnt[s[i]]++ ;
						letters.insert(s[i]) ;
					}
				it=letters.begin() ;
				while(it!=letters.end())
					{
						ans/=fac[cnt[*it]] ;
						it++ ;
					}
				cout<< "Data set " << tc << ": " << ans << endl ;
			}
	}
