#include <bits/stdc++.h>
using namespace std ;
int main()
{
  long long int r, a, b, c, d , n, temp, i, j ;
  while(cin>>n>>temp)
  {
    if(n==0) break ;
    r=sqrt(temp) ;
    if(r * r == temp && r % 2 == 1) {
        } else if(r % 2 == 1) r += 2;
        else r++;
    a= r*r ;
    b= r*r - 3*r + 3 ;
    c= r*r - 2*r + 2 ;
    d= r*r - r + 1 ;
    if(temp<=b)
    {
      i=(n/2) + (r/2) ;
      j=(n/2) + b - (r/2) - temp ;
    }
    else if(temp>b && temp<=c)
    {
      i=(n/2) + c - (r/2) -temp ;
      j=(n/2) - (r/2) ;
    }
    else if(temp>c && temp<=d)
    {
      i=(n/2) - (r/2) ;
      j=(n/2) - d + (r/2) + temp ;
    }
    else if(temp>d && temp<=a)
    {
      i=(n/2) - a + (r/2) + temp ;
      j=(n/2) + (r/2) ;
    }
    cout<< "Line = "<<i+1 << ", column = " << j+1 << "." << endl ;
  }
  return 0 ;
}
