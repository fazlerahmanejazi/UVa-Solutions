#include <bits/stdc++.h>
using namespace std ;


int queens[110][8], row[8]={0} ;
int n=0 ;


bool place(int c, int r)
{  for(int prev=0 ; prev<c ; prev++)
     if(row[prev]==r || (abs(row[prev] - r) == abs(prev - c)))
       return false ;
    return true ;
}

void backtrack(int c)
{
  if(c==8)
  { for(int i=0 ; i<8 ; i++)
    queens[n][i]=row[i] ;
    n++ ;
    return ;
  }

  for(int r=0 ; r<8 ; r++)
    { if(place(c,r))
      { row[c]=r ;
        backtrack(c+1) ;
      }
    }
}


int main()
{  backtrack(0) ;
  int row_input[8], Case = 1;

   while (scanf("%d", &row_input[0]) != EOF)
    {
       for (int i = 1; i < 8; ++i)
           cin>> row_input[i] ;

       for (int i = 0; i < 8; ++i)
           row_input[i]-- ;

      int Min=10000 ;
       for (int i = 0; i < n; i++)
       {
           int M = 0;
           for (int c = 0; c < 8; ++c)
               if (queens[i][c] != row_input[c])
                   ++M;
           if (M < Min) Min = M;
       }
       printf("Case %d: %d\n", Case++, Min);
   }
   return 0 ;
 }
