#include <bits/stdc++.h>
using namespace std ;

int gcd(int r, int s) {
    int t;
    while(r%s)
        t = r, r = s, s = t%s;
    return s;
}

int main()
{ int n, T=1, A, B, C, k,chk, x , y, z;
  string a, b, c ;
  int temp,num ;
  float f ;
  while(cin>> n && n!=0)
  { k=n ;  a.clear() ; b.clear() ; c.clear() ; num=0 ; chk=1 ;
    while(k--)
    {
      cin>> temp ;
      num=num+temp ;
    }
    if(num<0) chk=-1 ;
    num=abs(num) ;

    f=(float)num/(float)n ;

    cout<< "Case " << T<< ":" << endl ;

    if(f==floor(f))
    {
      if(chk==1) {cout<< f <<endl ;}
      else {cout<< "- "<< f <<endl ;}
    }
    else
    {
      if(f<1)
      { //f=(float)n/(float)num ;
        //if(f==floor(f)) { n=n/num ; num=1 ;}
        f=gcd(num,n) ;
        num=num/f ; n=n/f ;
        a=to_string(num) ;
        b=to_string(n) ;
        A=a.length() ; B=b.length() ;

        if(chk==1)
        {
          for(int i=0 ; i<B-A ; i++) cout<< " " ;
          cout<< a << endl ;
          for(int i=0 ; i<B ; i++) cout<< "-" ; cout<< endl ;
          cout<< b << endl ;
        }
        else
        {
          cout<< "  " ; for(int i=0 ; i<B-A ; i++) cout<< " " ;
          cout<< a << endl ;
          cout<< "- " ; for(int i=0 ; i<B ; i++) cout<< "-" ; cout<< endl ;
          cout<< "  " ; cout<< b << endl ;
        }
      }

      else
      { y=num/n ;
        x=num%n ;
        z=n ;
        //f=(float)z/(float)x ;
        //if(f==floor(f)) { z=z/x ; x=1 ;}
        f=gcd(x,z) ;
        x=x/f ; z=z/f ;
        a=to_string(x) ;
        b=to_string(y) ;
        c=to_string(z) ;
        A=a.length() ; B=b.length() ; C=c.length() ;
        if(chk==1)
       {
        for(int i=0 ; i<B ; i++) cout<< " "  ; for(int i=0 ; i<C-A ; i++) cout<< " " ; cout<< a << endl ;
        cout<< b ; for(int i=0 ; i<C ; i++) cout<< "-" ; cout<< endl ;
        for(int i=0 ; i<B ; i++) cout<< " "  ; cout<< c << endl ;
       }
       else
       {
         cout<< "  " ; for(int i=0 ; i<B ; i++) cout<< " "  ; for(int i=0 ; i<C-A ; i++) cout<< " " ; cout<< a << endl ;
         cout<< "- " ; cout<< b ; for(int i=0 ; i<C ; i++) cout<< "-" ; cout<< endl ;
         cout<< "  " ; for(int i=0 ; i<B ; i++) cout<< " "  ; cout<< c << endl ;
       }

      }
    } T++ ; a.clear() ; b.clear() ; c.clear() ;
  }
  return 0 ;
}
