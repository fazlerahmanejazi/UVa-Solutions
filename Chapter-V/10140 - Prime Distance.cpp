#include <bits/stdc++.h>
using namespace std ;

vector<bool> prime(47010, true) ;
vector<int> P ;
long long int L, U ;
bool exists ;

void sieve()
  {
    prime[1]=false ;
    for (int p=2 ; p*p<=47000 ; p++)
      if (prime[p])
        for (int i=p*2 ; i<=47000 ; i+=p)
          prime[i]=false ;
    for(int i=2 ; i<=47000 ; i++)
      if(prime[i]) P.push_back(i) ;
  }

bool isprime(long long int n)
  {
    if(n<47000) return prime[n] ;
    int k=sqrt(n) ;
    for(int i=0 ; i<P.size() && P[i]<=k ; i++)
      if(n%P[i]==0) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    sieve() ;
    while(cin>> L >> U)
      {
        exists=false ;
        int maxM=-INT_MAX, minM=INT_MAX ;
        pair<int, int> m, M ;
        long long int i, prev ;
        for(i=L ; i<=U ; i++)
          if(isprime(i))
            {
              prev=i ;
              break ;
            }
        for(i=i+1 ; i<=U ; i++)
          if(isprime(i))
            {
              if(i-prev>maxM)
                {
                  M=make_pair(prev, i) ;
                  maxM=i-prev ;
                }
              if(i-prev<minM)
                {
                  m=make_pair(prev, i) ;
                  minM=i-prev ;
                }
              prev=i ;
              exists=true ;
            }
        if(exists) cout<< m.first << "," << m.second << " are closest, " << M.first << "," << M.second << " are most distant." << endl ;
        else cout << "There are no adjacent primes." << endl ;
      }
  }
