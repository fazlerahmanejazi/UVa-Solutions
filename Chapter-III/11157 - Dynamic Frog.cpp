#include<bits/stdc++.h>
using namespace std ;

int main()
{
  int T, N, q=0 ;
  char a,w ;
  int D, temp, max ;
  cin>>T ;
  for(int t=1 ; t<=T ; t++)
  { max=0 ;
    scanf("%d %d ", &N, &D);
    vector<int> f, b ;
    while(N--)
     {
       scanf(" %c-%d ", &a, &temp) ;
       if(a=='B')
       {
         f.push_back(temp) ;
         b.push_back(temp) ;
       }
       else
       {
        if(q==0)
         {
           f.push_back(temp) ;
           q=1 ;
         }
        else
         {
           b.push_back(temp) ;
           q=0 ;
         }
       }
     }
   f.push_back(0) ; f.push_back(D) ;
   b.push_back(0) ; b.push_back(D) ;
    sort(f.begin(), f.end()) ;
    sort(b.begin(), b.end()) ;

   for(int j=0 ; j<f.size() ; j++)
   {
    if(max<f[j]-f[j-1]) max=f[j]-f[j-1] ;
   }

   for(int j=0 ; j<b.size() ; j++)
   {
     if(max<b[j]-b[j-1]) max=b[j]-b[j-1] ;
   }
  cout<< "Case "<<t<<": "<<max << endl ;
  }
   return 0 ;
}
