#include <bits/stdc++.h>
using namespace std ;

int main ()
{
    int n,m;
    int c=0;
   while(cin >> m >> n)
   {
       if (n ==0 && m ==0) break;
       c++;
       if (c > 1) cout << '\n';
       int field[102][102] = {0};
      for (int i=1; i<m+1; i++)
          for (int j=1; j<n+1; j++)
          {
              char t;
              cin >> t;
              if (t == '*')
                  {

                      field[i][j] = -1;
                      if (field[i-1][j] != -1) field[i-1][j]++;
                      if (field[i-1][j-1] != -1) field[i-1][j-1]++;
                       if (field[i-1][j+1] != -1) field[i-1][j+1]++;
                      if (field[i][j-1] != -1) field[i][j-1]++;
                      if (field[i+1][j] != -1) field[i+1][j]++;
                      if (field[i+1][j+1] != -1) field[i+1][j+1]++;
                      if (field[i+1][j-1] != -1) field[i+1][j-1]++;
                      if (field[i][j+1] != -1) field[i][j+1]++;
                  }
          }

           cout << "Field #" << c << ":\n";
            for (int i=1; i<m+1; i++)
           {

                for (int j=1; j<n+1; j++)
                    {
                        if (field[i][j] == -1) cout << '*';
                        else cout << field[i][j];
                }
                cout << "\n";
           }

   }

    return 0;
}
