#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int T, n, M, index, temp  ;
  cin>> T ;
  for(int tc=1 ; tc<=T ; tc++ )
  {
    cin>> n ;
    vector<long int> rung(n+1), diff(n+1) ;
    cin>> rung[0] ;
    diff[0]=rung[0] ;
    M=diff[0] ;
    index=0 ;
    for(int i=1 ; i<n ; i++)
     {
       cin>> rung[i] ;
       diff[i]=rung[i]-rung[i-1] ;
       if(M<diff[i]) { M=diff[i] ; index=i ; }
     }
     temp=M ;
    for(int i=index+1 ; i<n ; i++)
     {
       if(diff[i]==temp-1)
        {
          temp=temp-1 ;
        }
       else if(diff[i]>=temp)
        {
          M++ ;
          break ;
        }
     }
     cout<< "Case "<<tc<<": "<<M<< endl ;
  }
  return 0;
}
