#include<bits/stdc++.h>
using namespace std;


int main()
{
    int tc, kk=1, n;
    long long arr[100000+2];
    string s;
    char ch;
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Case "<<kk++<<":\n";
        for(int i=0;i<n;i++)
        {
            int st=i;
            while(i+1<n && arr[i+1]==arr[i]+1)
                i++;
            int d=i;
            if(st==d) cout<<"0"<<arr[i]<<"\n";
            else
            {
                cout<<"0"<<arr[st]<<"-";
                string s1 = "0"+to_string(arr[st]);
                string s2 = "0"+to_string(arr[d]);
                int pos=0;
                while(s1[pos]==s2[pos])
                    pos++;
                for(int j=pos;j<s2.size();j++)
                    cout<<s2[j];
                cout<<"\n";
            }
        }
        cout<<"\n";
    }
return 0;
}
