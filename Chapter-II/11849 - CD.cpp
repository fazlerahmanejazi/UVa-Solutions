#include <bits/stdc++.h>
using namespace std ;

int main()
{
    long long m,n,i,temp,c ;
    map<long, long> a;
    while(cin>>n>>m && n!=0 && m!=0)
    {
        c=0;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            a[temp]=1;
        }

        for(i=0;i<m;i++)
        {
            cin>>temp;
            if(a[temp]==1)
             c++;
        }

       a.clear();
        cout<<c<<endl;
    }

return 0;
}
