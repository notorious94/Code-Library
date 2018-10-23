#include<bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b&1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll power(ll a, ll b, ll c)
{
	ll x = 1, y = a;
	while(b>0)
    {
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b >>= 1;
	}
	return x;
}

bool witness(ll a,ll n)
{
    ll t = 0, u = n-1;
    while(u%2==0)
    {
        u>>=1;
        t++;
    }
    ll x[t+1];
    x[0] = power(a,u,n);
    for(int i=1;i<=t;i++)
    {
        x[i] = mulmod(x[i-1],x[i-1],n);
        if(x[i]==1 && x[i-1]!=1 && x[i-1]!=n-1)
            return true;
    }
    if(x[t]!=1)
        return true;
    return false;
}

bool miller_rabin(ll p,ll k=2)
{
    srand(time(NULL));
    for(int i=1;i<=k;i++)
    {
        ll a = 2 + rand()%(p-4);
        if(witness(a,p))
            return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ll p,t;
    cin>>t;
    while(t--)
    {
        scanf("%lld",&p);
        if(miller_rabin(p))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
