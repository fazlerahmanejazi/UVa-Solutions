#include <bits/stdc++.h>
using namespace std ;

int r, c, n, temp1, temp2, temp3, a, b ;
int land[1055][1055] ;
pair<int, int> s, e, temp, T ;

bool check(int x, int y )
  {
    if(x>=0 && x<r && y>=0 & y<c) return true ;
    else false ;
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> r >> c)
  {
    if(r==0 && c==0) break ;
    cin>> n ;
    for(int i=0 ; i<r ; i++)
    	for(int j=0 ; j<c ; j++)
    		land[i][j]=-1 ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> temp1 >> temp2 ;
        for(int j=0 ; j<temp2 ; j++)
          {
            cin>> temp3 ;
            land[temp1][temp3]=10000000 ;
          }
      }

    cin>> temp1 >> temp2 ;
    s=make_pair(temp1, temp2) ;
    cin>> temp1 >> temp2 ;
    e=make_pair(temp1, temp2) ;
    queue<pair<int,int> > q ;
    land[s.first][s.second]=0 ;
    q.push(s) ;
    while(!q.empty())
      {
        temp=q.front() ;
        q.pop() ;
        a=temp.first ;
        b=temp.second ;
        if(check(a+1, b))
          {
            if(land[a+1][b]==-1)
             {
               land[a+1][b]=land[a][b]+1 ;
               T=make_pair(a+1,b) ;
               q.push(T) ;
            }
          }
        if(check(a-1, b))
          {
            if(land[a-1][b]==-1)
             {
               land[a-1][b]=land[a][b]+1 ;
               T=make_pair(a-1,b) ;
               q.push(T) ;
            }
          }
        if(check(a, b+1))
            {
              if(land[a][b+1]==-1)
               {
                 land[a][b+1]=land[a][b]+1 ;
                 T=make_pair(a,b+1) ;
                 q.push(T) ;
              }
            }
        if(check(a, b-1))
              {
                if(land[a][b-1]==-1)
                 {
                   land[a][b-1]=land[a][b]+1 ;
                   T=make_pair(a,b-1) ;
                   q.push(T) ;
                }
              }
      }
    cout<< land[e.first][e.second] << endl ;
  }
  return 0 ;
}
