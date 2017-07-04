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
    string s1, s2 ;
    vi ans ;
    bool check, newline=false ;
    int start ;
    while(cin>> s1 >> s2)
      {
        ans.assign(111, 0) ;
        for(int i=s1.length()-1, idx=0 ; i>=0 ; i--, idx++)
          ans[idx]+=s1[i]-'0' ;
        for(int i=s2.length()-1, idx=0 ; i>=0 ; i--, idx++)
          ans[idx]+=s2[i]-'0' ;
        check=true ;
        start=0 ;
        if(newline) cout<< endl ;
        while(check)
          {
            check=false ;
            for(int i=0 ; i<=110; i++)
              {
                if(ans[i] && ans[i+1])
                  {
                    ans[i]-- ;
                    ans[i+1]-- ;
                    ans[i+2]++ ;
                    check=true ;
                    break ;
                  }
                if(ans[i]>1)
                  {
                    ans[i]-=2 ;
                    if(i==0) ans[1]++ ;
                    else if(i==1)
                      {
                        ans[2]++ ;
                        ans[0]++ ;
                      }
                    else
                      {
                        ans[i+1]++ ;
                        ans[i-2]++ ;
                      }
                    check=true ;
                    break ;
                  }
              }
          }
        for(int i=110 ; i>=0 ; i--)
          if(ans[i])
            {
              start=i ;
              break ;
            }
        for(int i=start ; i>=0 ; i--)
          cout<< ans[i] ;
        cout<< endl ;
        newline=true ;
      }
  }
