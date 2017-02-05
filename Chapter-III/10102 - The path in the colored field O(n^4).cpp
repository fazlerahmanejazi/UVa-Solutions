#include <bits/stdc++.h>
using namespace std ;

int main()
{
  int n, m ;
  while(cin>>n)
  {
    m=0 ;
    vector< vector<int> > field(n, vector<int>(n)) ;
    int temp=10000 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
           scanf("%1d",&field[i][j]) ;

    for(int i=0 ; i<n ; i++)
    {
      for(int j=0 ; j<n ; j++)
      {
        if(field[i][j]==1)
        { temp=10000 ;
          for(int a=0 ; a<n ; a++)
          {
            for(int b=0 ; b<n ; b++)
            {
               if(field[a][b]==3)
               {
                 if(temp>abs(b-j)+abs(a-i)) temp=abs(b-j)+abs(a-i) ;
               }
            }
          }
         if(m<temp) m=temp ;
        }
      }
    }
   printf("%d\n", m);
   }
  return 0 ;
}
