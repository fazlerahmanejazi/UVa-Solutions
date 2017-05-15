#include <bits/stdc++.h>
using namespace std ;

int n, r, c ;
long long int board[16][16], ans ;
string s ;

void place(int r, int c)
  {
    for(int i=0 ; i<n ; i++)
      board[i][c]=-1 ;
    if(c-1>=0)
      {
        if(r-1>=0) board[r-1][c-1]=-1 ;
        if(r+1<n) board[r+1][c-1]=-1 ;
        board[r][c-1]=-1 ;
      }
    if(c+1<n)
      {
        if(r-1>=0) board[r-1][c+1]=-1 ;
        if(r+1<n) board[r+1][c+1]=-1 ;
        board[r][c+1]=-1 ;
      }
    board[r][c]=0 ;
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>> s)
    {
      n=s.length() ;
      ans=0 ;
      memset(board, 0, sizeof(board)) ;
      for(int i=0 ; i<n ; i++)
        {
          if(s[i]<='9' && s[i]>='1')
            {
              c=i ;
              r=s[i]-'0'-1 ;
              place(r, c) ;
            }
          else if(s[i]!='?')
            {
              c=i ;
              r=s[i]-'A'+9 ;
              place(r, c) ;
            }
        }
      for(int i=0 ; i<n ; i++)
        if(board[i][0]==0) board[i][0]++ ;
      for(int j=0 ; j<n-1 ; j++)
        {
          for(int i=0 ; i<n ; i++)
            {
              if(board[i][j]>=0)
                 {
                  for(int k=i-2 ; k>=0 ; k--)
                    if(board[k][j+1]>=0) board[k][j+1]+=board[i][j] ;
                  for(int k=i+2 ; k<n ; k++)
                    if(board[k][j+1]>=0) board[k][j+1]+=board[i][j] ;
                 }
            }
        }
      for(int i=0 ; i<n ; i++)
        if(board[i][n-1]>=0) ans+=board[i][n-1] ;
      cout<< ans << endl ;
    }
    return 0 ;
}
