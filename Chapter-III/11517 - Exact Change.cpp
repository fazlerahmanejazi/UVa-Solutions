
#include <bits/stdc++.h>
using namespace std ;

int main()
{ int tc, n, ans, temp ;
  long int M ;
  vector<int> coins ;
  cin>> tc ;
  while(tc--)
  { coins.clear() ;
    M=0 ;
    cin>> ans >> n ;
    for(int i=0 ; i<n ; i++)
    {
       cin>> temp ;
       coins.push_back(temp) ;
       if(M<ans) M+=temp ;
    }
    vector<int> N(M+1) ;
    for(int i=0 ; i<=M ; i++)
      N[i]=n ;
    N[0]=0 ;

    for(int i=0 ; i<n ; i++)
      for(int j=M ; j>=coins[i] ; j--) 
        N[j]=min(N[j], N[j-coins[i]]+1) ;

    int pay=ans ;
    while(pay<M && N[pay]==n) pay++ ;

    cout<< pay << " " << N[pay] << endl ;

  }
return 0 ;
}
