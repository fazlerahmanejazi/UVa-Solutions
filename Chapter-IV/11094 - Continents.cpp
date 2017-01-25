#include <bits/stdc++.h>
using namespace std ;

int n, m, x, y, curr, ans ;
vector<vector<char> > grid ;
char temp ;

int FloodFill(int r, int c)
{
  if(c==m) c=0 ;
  else if(c==-1)  c=m-1 ;
  if(r<0 || r>=n || c<0 || c>=m) return 0 ;
  if(grid[r][c]!=temp) return 0 ;
  grid[r][c]='.' ;
  int ans=1 ;
  ans+=FloodFill(r+1, c) + FloodFill(r, c+1) + FloodFill(r-1, c) +FloodFill(r, c-1) ;
  return ans ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> n >> m)
  {
    grid.clear() ;
    grid.resize(n) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> temp ;
          grid[i].push_back(temp) ;
        }
    cin>> x >> y ;
    temp=grid[x][y] ;
    ans=FloodFill(x,y) ;
    ans=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
      {
        if(grid[i][j]==temp)
        {
          curr=FloodFill(i,j) ;
          if(curr>ans) ans=curr ;
        }
      }
    cout<< ans << endl ;
  }
  return 0 ;
}
