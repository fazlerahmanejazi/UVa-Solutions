#include <bits/stdc++.h>
using namespace std ;

int n, result, T ;
vector<vector<char> > grid ;
char temp ;

void FloodFill(int r, int c)
{
  if(r<0 || r>=n || c<0 || c>=n || grid[r][c]=='.') return ;
  grid[r][c]='.' ;
  int ans=1 ;
  FloodFill(r+1, c) ;
  FloodFill(r, c+1) ;
  FloodFill(r-1, c) ;
  FloodFill(r, c-1) ;
  return ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;
  for(int tc=1 ; tc<=T ; tc++)
  {
    result=0 ;
    cin>> n ;
    grid.clear() ;
    grid.resize(n) ;
    for(int i=0 ; i<n ; i++)
     for(int j=0 ; j<n ; j++)
       {
         cin>> temp ;
         grid[i].push_back(temp) ;
       }

    for(int i=0 ; i<n ; i++)
       for(int j=0 ; j<n ; j++)
            if(grid[i][j]=='x')
                {
                  result++ ;
                  FloodFill(i,j) ;
                }
    cout<< "Case "<< tc <<": "<< result << endl ;
  }
  return 0 ;
  }
