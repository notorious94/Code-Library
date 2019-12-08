#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll o[65],z[65];

bool checkbit(ll N,int pos)
{
    return (bool)(N & (1LL<<pos));
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    ll n,x,m = 1e9+7;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        for(int j=0; j<=61; j++)
        {
            if(checkbit(x,j))   o[j]++;
            else                z[j]++;
        }
    }

    ll ans = 0;

    for(ll i=0; i<=61; i++)
        ans = (ans+((((o[i]*z[i])%m)*((1LL<<i)%m))%m))%m;

    cout<<ans<<endl;

    return 0;
}
