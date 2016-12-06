
#include <bits/stdc++.h>
using namespace std ;

int main()
{
  int N, i, j, k, temp ;
  stack<int> a ;
     j=1 ;
     for(i=0 ; i<N ; i++)
     {
      cin>> temp ;
     if(temp>j)
     {
       for(k=j ; k<=temp ; k++)
         a.push(k) ;
       a.pop() ;
       j=temp+1 ;
     }
     else
     {
       if(!a.empty() && a.top() == temp)
       a.pop() ;

       else

     }

     }
    if(a.size() == 0) cout<< "Yes" << endl ;
    else cout<< "No" << endl ;

  return 0 ;
}
