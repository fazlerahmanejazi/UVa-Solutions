#include <bits/stdc++.h>
using namespace std ;

int n, m, num, T, pos ;
string temp1, temp2 ;
vector<bool> visit;
vector<int> topo, ans ;
vector<vector<int>> adj ;
vector<vector<int>> adj_rev ;
map<string,int> avail ;
vector<int> postvisit ;

void dfs_rev(int t)
{
  visit[t]=true ;
  num++ ;
  for(int i=0 ; i<adj_rev[t].size() ; i++)
      if(visit[adj_rev[t][i]]!=true)
         dfs_rev(adj_rev[t][i]) ;
  postvisit[t]=num++ ;
}

void dfs(int t)
{
  visit[t]=true ;
  for(int i=0 ; i<adj[t].size() ; i++)
      if(visit[adj[t][i]]!=true)
         dfs(adj[t][i]) ;
  ans.push_back(t) ;
}

int main()
{
  ios_base::sync_with_stdio (false) ;
  T=1 ;
  while(cin>> n >> m)
  {
    num=1 ;
    if(n==0 && m==0) break ;
    cout<< "Calling circles for data set "<< T << ":" << endl ;
    if(n==1 && m==0) { cout<<endl ; T++ ; continue ;}
    visit.clear() ;
    avail.clear() ;
    adj.clear() ;
    adj.resize(n+1) ;
    adj_rev.clear() ;
    adj_rev.resize(n+1) ;
    visit.assign(n+1, false) ;
    postvisit.clear() ;
    postvisit.resize(n+1) ;
    postvisit[0]=0 ;
    map<string, int> cnc ;
    map<int, string> ncn ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> temp1 >> temp2 ;
        if(avail[temp1]==0)
        {
          cnc[temp1]=num ;
          ncn[num]=temp1 ;
          avail[temp1]=1 ;
          num++ ;
        }
        if(avail[temp2]==0)
        {
          cnc[temp2]=num ;
          ncn[num]=temp2 ;
          avail[temp2]=1 ;
          num++ ;
        }
        adj[cnc[temp1]].push_back(cnc[temp2]) ;
        adj_rev[cnc[temp2]].push_back(cnc[temp1]) ;
      }
    num=1 ;

    for(int i=1 ; i<=n ; i++)
     if(visit[i]==false)
       dfs_rev(i) ;

    visit.assign(n+1, false) ;
    for(int i=1 ; i<=n ; i++)
     {
       pos=max_element(postvisit.begin(), postvisit.end())-postvisit.begin() ;
       postvisit[pos]=0 ;
       if(visit[pos]==false)
       {
         ans.clear() ;
         dfs(pos) ;
         for(int j=0 ; j<ans.size() ; j++)
             {
               if(j!=ans.size()-1) cout<< ncn[ans[j]] << ", " ;
               else cout<< ncn[ans[j]] << endl  ;
             }
       }
     }
    cout<< endl ;
    T++ ;
   }
   return 0 ;
 }
