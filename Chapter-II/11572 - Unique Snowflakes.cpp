#include <bits/stdc++.h>
using namespace std ;

int main() {
  int t, n, id;
  cin>>T ;
  while (T--) {
    map<int, int> l;
    cin>> n ;
    int ans = 0, begin = 1;
    for (int i = 1; i <= n; i++)
   {
      cin>> id ;
      if (l[id] >= begin)
      {
        begin = l[id] + 1;
      }
      l[id] = i;
      ans = (i - begin + 1) > ans ? (i - begin + 1) : ans;
    }
    cout<< ans < endl ;
  }
  return 0;
}
