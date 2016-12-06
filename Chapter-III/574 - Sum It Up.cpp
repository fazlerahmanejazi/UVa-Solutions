#include<bits/stdc++.h>
using namespace std ;
int sum=0, t, n, val ;
vector<int> a, ans ;
set<vector<int>> ANS;

void add(int k, int sum)
{
  if(sum==t)
  {
   ANS.insert(ans) ;
  }
  else
  {
    for(int i=k ; i<a.size() ; i++)
    {
      if(a[i]+sum<=t)
      {
        ans.push_back(a[i]) ;
        add(i+1, a[i]+sum) ;
        ans.pop_back() ;
      }
    }
  }
}


int main()
{     while(cin>> t >> n )
    { if(t==0 && n==0) break ;
       a.clear() ; ans.clear() ; ANS.clear() ;
       for(int q=0 ; q<n ; q++)
      {
        scanf("%d", &val) ;
        a.push_back(val) ;
      }
      add(0,0) ;
      printf("Sums of %d:\n",t);
      if(ANS.size()==0)
      {
        printf("NONE\n") ;
        continue ;
      }
      set<vector<int> > :: iterator it ;
      it=ANS.end() ;
      for(it--; ; it--)
        {
            vector<int> vi = *it ;
            printf("%d",vi[0]) ;
            for(int i = 1; i<vi.size(); i++)
            {
                printf("+%d",vi[i]) ;
            }
            printf("\n") ;
            if(it==ANS.begin()) break;
        }
    }
return 0 ;
}
