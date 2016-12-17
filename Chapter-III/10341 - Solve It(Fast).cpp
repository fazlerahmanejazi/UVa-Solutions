#include <bits/stdc++.h>
using namespace std ;

#define least 0.000000000001

int p,q,r,s,t,u;

double f(double x)
{
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double fd(double x)
{
  return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;
}

double solve()
{
  if (f(0)==0) return 0;
  for (double x=0.5; ;)
  {
    double x1 = x - f(x)/fd(x);
    if (fabs(x1-x) < least) return x;
    x = x1;
  }
}

int main()
{
  while(cin>>p>>q>>r>>s>>t>>u)
  {
    if (f(0) * f(1) > 0) cout<< "No solution" << endl ;
    else cout<< fixed << setprecision(4)<< solve() << endl ;
  }
}
