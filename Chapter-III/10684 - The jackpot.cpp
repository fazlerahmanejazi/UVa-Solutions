#include <bits/stdc++.h>
using namespace std ;

int main()
{ int N, temp, p, max ;
  while(cin>>N)
  { if(N==0) break ;
    max=0 ;
    vector<long int> a ;
    int i,j ;
    j=0 ;
    for(i=0 ; i<N ; i++)
    {
      cin>> temp ;
      if(temp>=0)
      {
        a.push_back(temp) ;
        p=1 ;
        i++ ;
        break ;
      }
    }
    for( ; i<N ; i++)
    {
      cin>> temp ;
      if(temp>=0 && p==1) a[j]=a[j]+temp ;
      else if (temp<0 && p==-1) a[j]=a[j]+temp ;
      else
      {
        a.push_back(temp) ;
        j++ ;
        if(p==1) p=-1 ;
        else p=1 ;
      }
    }
    for(i=0 ; i<a.size() ; i++)
      if(max<a[i]) max=a[i] ;

    max=a[0] ;
    if(a.size()>=2)
    {
      for( i=1 ; i<a.size() ; i++)
       {
          if(a[i]<0)
          { if(max<a[i-1]) max=a[i-1] ;

            if(abs(a[i])>a[i-1]) { a[i-1]=0 ; a[i]=0 ;}
            else { a[i]=a[i]+a[i-1] ; a[i-1]=0 ;}
          }
          else
          {
            a[i]=a[i]+a[i-1] ;
            a[i-1]=0 ;
          }
       }
    }
    for(i=0 ; i<a.size() ; i++)
      if(max<a[i]) max=a[i] ;
    if(max>0) cout<< "The maximum winning streak is " << max << "." << endl ;
    else cout<< "Losing streak." << endl ;
  }
  return 0 ;
}
