#include <bits/stdc++.h>
using namespace std ;
int main()
{ // +z=1, -z=2, +y=3, -y=4, +x=5, -x=6,
  long long int L ;
  int a=5 ;
  string temp ;
  while(cin>>L && L!=0)
  { a=5 ;
    while(--L)
    {
      cin>> temp ;
      if(temp[0]=='+' && temp[1]=='z')
      {
        if(a==1) a=6 ;
        else if(a==2) a=5 ;
        else if(a==5) a=1 ;
        else if(a==6) a=2 ;
      }

      else if(temp[0]=='-' && temp[1]=='z')
      {
        if(a==1) a=5 ;
        else if(a==2) a=6 ;
        else if(a==5) a=2 ;
        else if(a==6) a=1 ;
      }

       else if(temp[0]=='+' && temp[1]=='y')  // +z=1, -z=2, +y=3, -y=4, +x=5, -x=6,
      {
        if(a==3) a=6 ;
        else if(a==4) a=5 ;
        else if(a==5) a=3 ;
        else if(a==6) a=4 ;
      }

      else if(temp[0]=='-' && temp[1]=='y')  // +z=1, -z=2, +y=3, -y=4, +x=5, -x=6,
      {
        if(a==3) a=5 ;
        else if(a==4) a=6 ;
        else if(a==5) a=4 ;
        else if(a==6) a=3 ;
      }

      temp.clear() ;
    }

     if(a==1) cout<< "+z" ;
     if(a==2) cout<< "-z" ;
     if(a==3) cout<< "+y" ;
     if(a==4) cout<< "-y" ;
     if(a==5) cout<< "+x" ;
     if(a==6) cout<< "-x" ;

  }
  return 0 ;
}
