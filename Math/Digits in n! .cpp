#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define pi acos(-1.0)

typedef long long ll;
typedef unsigned long long ull;

int digit(int n, int b)
{
    if(n==0)
        return 1;
    return floor(((n+0.5)*log(n) - n + 0.5*log(2*pi))/log(b))+1;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b;
    sif(t);

    for(int i=1;i<=t;i++)
    {
        sf("%d%d",&a,&b);
        pf("Case %d: %d\n",i,digit(a,b));
    }
    return 0;
}
