#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int tc, x, y, z, temp, a, b, c, u, v, q ;
  bool chk ;
  vector<int> ans(3) ;
  cin>> tc ;
  while(tc--)
  {
    cin>> a >> b >> c ;
    chk=false ;
    q= sqrt(c)  ;
    for(x=-q ; x<=q ; x++)
    {
      temp=a-x ;
      for(y=-q ; y<=q ; y++)
      {
        z=temp-y ;
        u= x*y*z ;
        v= x*x + y*y + z*z ;
        if(u==b && v==c)
          {
            ans[0]=x ;
            ans[1]=y ;
            ans[2]=z ;
            chk=true ;
            break ;
          }
      }
      if(chk) break ;
    }

    sort(ans.begin(), ans.end()) ;
    if(ans[1]==ans[0] || ans[2]==ans[1]) chk=false ;
    if(!chk) cout<< "No solution." << endl ;
    else cout<< ans[0] << " " << ans[1] << " " << ans[2] << endl ;

  }
  return 0 ;
}
