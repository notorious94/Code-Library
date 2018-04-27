#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

ll bigMod(ll n, ll p, ll m)
{
    if(!p)  return 1%m;
    /// Power is Zero therefore -> n ^ 0 == 1

    if(p&1) return ( bigMod(n,p-1,m)%m * n%m ) % m;
    /// Power is Odd Ex: (2^3) % m == ((2^2) % m * (2^1) % m) % m
    /// BIG_MOD ((n^p-1)%m * n^1%m)%m

    else{
        /// Power is Even EX: (2^4) % m == (2^2) % m * (2^2) % m
        /// Therefore a = (n^(p/2))%m
        /// (a * a) % m
        ll a = bigMod(n,p/2,m)%m;
        return (a*a)%m;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ll n,p,m;
    while(scanf("%lld%lld%lld",&n,&p,&m)!=EOF)
        pf("%lld\n",bigMod(n,p,m));

    return 0;
}
