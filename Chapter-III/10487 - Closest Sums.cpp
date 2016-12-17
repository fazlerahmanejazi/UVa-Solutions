#include <bits/stdc++.h>
using namespace std ;


int main()
{ ios_base::sync_with_stdio (false) ;
   int n, m, temp, tc=1, c, cindex ;
   vector<int> N, M, sum ;
   while(cin>>n && n)
   { N.clear() ; M.clear() ; sum.clear() ;
   	 cout<< "Case "<<tc<<":" << endl ;
     for(int i=0 ; i<n ; i++)
      {
        cin>> temp ;
        N.push_back(temp) ;
      }
     cin>>m ;
     for(int i=0 ; i<m ; i++)
      {
        cin>> temp ;
        M.push_back(temp) ;
      }
     for(int i=0 ; i<n-1 ; i++)
      {
        for(int j=i+1 ; j<n ; j++)
          {
            temp=N[i]+N[j] ;
            sum.push_back(temp) ;
          }
      }
      sort(sum.begin(), sum.end()) ;
    for(int i=0 ; i<m ; i++)
      { c=1000000000 ;
        for(int j=0 ; j<sum.size() ; j++)
          {
             temp=abs(M[i]-sum[j]) ;
             if(temp<c)
             {
               c=temp ;
               cindex=j ;
             }
          } cout<< "Closest sum to "<<M[i] <<" is "<<sum[cindex]<<"." << endl ;
      }
      tc++ ;
    }
return 0 ;
}
