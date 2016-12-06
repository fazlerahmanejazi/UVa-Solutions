#include<bits/stdc++.h>
using namespace std;


int main()
{
    double tmonth, downPay, price, interest[105], owe;
    int k, m;

    while(cin>>tmonth>>downPay>>price>>k && tmonth>=0)
    {
        owe=price;
        double monthlyPay=price/(double) tmonth;
        price+=downPay;
        for(int i=0;i<=tmonth;i++) interest[i]=-1;
        for(int i=0;i<k;i++)
        {
            cin>>m;
            cin>>interest[m];
        }
        for(int i=1;i<=tmonth;i++)
            if(interest[i]==-1) interest[i]=interest[i-1];

        int ans=-1;

        int i=0;
        while(ans==-1)
        {
            price=price-price*interest[i];
            if(price>owe) ans=i;
            owe-=monthlyPay;
            i++;
        }
        cout<<ans<<" month";
        if(ans!=1) cout<<"s";
        cout<<"\n";
    }
return 0;
}
