#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, temp, m ;
  while(cin>>n)
  {
    vector<int> x, y, X, Y ;
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<n ; j++)
          {
            scanf("%1d",&temp) ;
            if(temp==1)
            {
              x.push_back(i) ;
              y.push_back(j) ;
            }
            if(temp==3)
            {
              X.push_back(i) ;
              Y.push_back(j) ;
            }
          }
      }
      m=0 ;
      for(int i=0 ; i<x.size() ; i++)
        {
          temp= 100000 ;
          for(int j=0 ; j<X.size() ; j++)
            {
               temp=min(temp, abs(x[i]-X[j])+abs(y[i]-Y[j])) ;
            }
          m=max(m, temp) ;
        }
      printf("%d\n", m);
  }
  return 0 ;
}
