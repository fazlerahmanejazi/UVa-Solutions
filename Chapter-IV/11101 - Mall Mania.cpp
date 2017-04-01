#include <bits/stdc++.h>
using namespace std ;

int a, b, x, y, d, ans ;
bool mall[2005][2005], visit[2005][2005] ;
pair<pair<int, int>, int> temp ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> a)
    {
      if(a==0) break ;
      ans=0 ;
	    queue<pair<pair<int, int>, int> > graph ;
      memset(mall, false, sizeof(mall)) ;
      memset(visit, false, sizeof(visit)) ;
      for(int i=0 ; i<a ; i++)
        {
          cin>> x >> y ;
          graph.push(make_pair(make_pair(x,y), 0)) ;
          visit[x][y]=true ;
        }
      cin>> b ;
      for(int i=0 ; i<b ; i++)
        {
          cin>> x >> y ;
          mall[x][y]=true ;
        }
      while(!graph.empty())
        {
          temp=graph.front() ;
          graph.pop() ;
          int x=temp.first.first ; int y=temp.first.second ; int d=temp.second ;
          if(mall[x][y])
            {
              ans=d ;
              break ;
            }
          if(x+1<=2000 && !visit[x+1][y])
            {
              graph.push(make_pair(make_pair(x+1,y), d+1)) ;
              visit[x+1][y]=true ;
            }
          if(x-1>=0 && !visit[x-1][y])
            {
              graph.push(make_pair(make_pair(x-1,y), d+1)) ;
              visit[x-1][y]=true ;
            }
          if(y+1<=2000 && !visit[x][y+1])
            {
              graph.push(make_pair(make_pair(x,y+1), d+1)) ;
              visit[x][y+1]=true ;
            }
          if(y-1>=0 && !visit[x][y-1])
            {
              graph.push(make_pair(make_pair(x,y-1), d+1)) ;
              visit[x][y-1]=true ;
            }
        }
      cout<< ans << endl ;
    }
  return 0 ;
 }
