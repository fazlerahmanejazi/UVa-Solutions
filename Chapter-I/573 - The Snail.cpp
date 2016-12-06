#include <bits/stdc++.h>
using namespace std ;
int main()
{
   float h, u, d, f, c,day=1 ;
   while(cin>> h >> u >> d >> f)
   {
     f=(f*u)/100 ;
     while(1)
     {
       if(day==1)
       {
         c= c+ u-d ;
         if(c>=h) {cout<< "success on day " << day <<endl ; break ;}
         if(c<0) {cout<< "failure on day " << day <<endl ; break ;}
       }
       else
       {
         u=u-f ;
         c=c+u-d ;
         if(c>=h) {cout<< "success on day " << day <<endl ; break ;}
         if(c<0) {cout<< "failure on day " << day <<endl ; break ;}
       }
       day++ ;
     }
   }
      return 0 ;
}
