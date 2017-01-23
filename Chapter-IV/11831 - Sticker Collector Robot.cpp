#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, m, s, x, y, count ;
  char dir ;
  string d ;
  while(cin>> n >> m >> s && n)
  {
    count=0 ;
    vector< vector<char> > cells(n, vector<char>(m)) ;
    for(int i=0 ; i<n ; i++)
     for(int j=0 ; j<m ; j++)
       {
         cin>> cells[i][j] ;
         if(cells[i][j]=='N' || cells[i][j]=='S' || cells[i][j]=='L'|| cells[i][j]=='O')
          { x=i ; y=j ; dir=cells[i][j] ; }
       }
    cin>> d ;
    for(int i=0 ; i<s ; i++)
    {
      if(dir=='N')
       {
        if(d[i]=='D') dir='L' ;

        else if(d[i]=='E') dir='O' ;

        else if(d[i]=='F')
         {
          x=x-1 ;
          if(x<0 || cells[x][y]=='#')  x=x+1 ;
          else if(cells[x][y]=='*')
             {
               count++ ;
               cells[x][y]='.' ;
             }
         }
       }

       else if(dir=='S')
        {
         if(d[i]=='D') dir='O' ;

         else if(d[i]=='E') dir='L' ;

         else if(d[i]=='F')
          {
           x=x+1 ;
           if(x>=n || cells[x][y]=='#')  x=x-1 ;
           else if(cells[x][y]=='*')
              {
                count++ ;
                cells[x][y]='.' ;
              }
          }
        }

        else if(dir=='O')
         {
          if(d[i]=='D') dir='N' ;

          else if(d[i]=='E') dir='S' ;

          else if(d[i]=='F')
           {
            y=y-1 ;
            if(y<0 || cells[x][y]=='#')  y=y+1 ;
            else if(cells[x][y]=='*')
               {
                 count++ ;
                 cells[x][y]='.' ;
               }
           }
         }

         else if(dir=='L')
          {
           if(d[i]=='D') dir='S' ;

           else if(d[i]=='E') dir='N' ;

           else if(d[i]=='F')
            {
             y=y+1 ;
             if(y>=m || cells[x][y]=='#')  y=y-1 ;
             else if(cells[x][y]=='*')
                {
                  count++ ;
                  cells[x][y]='.' ;
                }
            }
          }
     }
     cout<< count << endl ;
   }
return 0 ;

  }
