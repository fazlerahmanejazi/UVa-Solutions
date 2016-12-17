#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, m, b1, b2, i, j ;
  while(cin>>n)
  {
    vector<int> books(n) ;
    for(i=0 ; i<n ; i++)
     cin>> books[i] ;
    cin>>m ;
    sort(books.begin(),books.end()) ;
    i=0 ; j=n-1 ;
    while(j>i)
    {
      while (i < j)
       {
           if (books[i] + books[j] < m)
               ++i;
           else if (books[i] + books[j] == m)
           {
               b1 = books[i];
               b2 = books[j];
               ++i; --j;
           }
           else
               --j;
       }
    }
    cout<< "Peter should buy books whose prices are "<<b1<<" and "<<b2<<"." << endl ;
    cout<< endl ;
  }
return 0;
}
