#include<bits/stdc++.h>
using namespace std ;

int main()
{ long int n[30001]={1} ;
  int N, c[5]={1,5,10,25,50} ;

  for(int i=0 ; i<5 ; i++)
    for(int j=c[i] ; j<30001 ; j++)
      n[j]+=n[j-c[i]] ;

  while(scanf("%d", &N) == 1)
      printf(n[N] == 1? "There is only %ld way to produce %d cents change.\n" :
               "There are %ld ways to produce %d cents change.\n", n[N], N);
  return 0 ;
}
