
#include <bits/stdc++.h>
using namespace std ;

int main()
{ string s[100], r[100] ;
  int i=0 ;
  int T ;
  cin>> T ;
  cin.ignore() ;
while(T--)
{
  while(getline(cin, s[i]) && s[i]!=" ")
  {
   r[i]=s[i] ;
   r[i].erase(remove(r[i].begin(), r[i].end(),' '), r[i].end());
   sort(r[i].begin(), r[i].end()) ;
   for(int k=0 ; k<r[i].length() ; k++) r[i][k]=tolower(r[i][k]) ;
   i++ ;
  }

  for(int j=0 ; j<i ; j++)
  {
    for(int k=j+1 ; k<i ; k++)
    {
      if(r[j]==r[k] && s[j]<s[k]) { cout<< s[j] << " = " << s[k] << endl ; }
      if(r[j]==r[k] && s[j]>s[k]) { cout<< s[k] << " = " << s[j] << endl ; }
    }
  }

}
  return 0 ;
}
