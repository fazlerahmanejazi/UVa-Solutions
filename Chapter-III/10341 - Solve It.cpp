#include <bits/stdc++.h>
using namespace std ;

#define least 0.000000000001

int p, q, r, s, t, u ;
  double f(double x)
  {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>>p>>q>>r>>s>>t>>u)
  {
    double L, R, m ;
    L=0 ; R=1 ;
    while(R-L>least)
    { m=(R+L)/2 ;
      if(f(m)<0) R=m ;
      else L=m ;
    }
    if(f(1)*f(0)>0) cout<< "No solution" << endl ;
    else cout<< fixed << setprecision(4)<< (L+R)/2 << endl ;
  }
  return 0;
}
