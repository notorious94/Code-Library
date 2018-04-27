#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void pf(ll n);

int main()
{
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);
    ll t, n;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n;
        printf("Case %lld:\n", i, n);
        pf(n);
        if(i!=t)
            cout<<endl;
    }
    return 0;
}

void pf(ll n)
{
    ll temp=n;
    ll r=floor(sqrt(n));
    ll count, div=1;

    for(ll i=2;i<=r;i++)
    {
        if(n%i==0)
        {
            count=0;
            while(n%i==0)
            {
                n/=i;
                count++;
            }
            printf("%lld^%lld\n", i, count);
        }
    }
    if(n!=1)
        printf("%lld^1\n", n);
}
