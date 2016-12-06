#include <bits/stdc++.h>
using namespace std ;
int main()
{  double h, m, ans, i, j ;
   char ch ;
   while(cin>> h >> ch >> m )
   { if(h==0 & m==0) break ;
   i=((h*30)+(m/2));
   j=(m*6);
   ans=abs(i-j) ;
   if(ans>180) ans=360-ans ;
   printf("%.3lf\n",ans);
   }
   return 0 ;
}
