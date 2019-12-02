#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 3e6+5;
int lp[N];
vector<int>prime;

void sieve(int limit = 3e6+1)
{
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}

ull phi[N],lcm[N];

void etf()
{
    for(int i=1;i<=3e6;i++) phi[i]=i;
    for(auto p : prime)
        for(int j=1;j*p<=3e6;j++)
        {
            phi[j*p]/=p;
            phi[j*p]*=p-1;
        }
}

void lcmSum()
{
    for(int i=1;i<=3e6;i++)
        for(int j=1;i*j<=3e6;j++)
            lcm[i*j]+=i*phi[i];
    for(int i=1;i<=3e6;i++)
    {
        lcm[i]=((lcm[i]-1)/2)*i;
        lcm[i]+=lcm[i-1];
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    sieve();
    etf();
    lcmSum();
    int t,n;
    scanf("%d",&t);
    for(int cn = 1;cn<=t;cn++)
    {
        scanf("%d",&n);
        printf("Case %d: %llu\n",cn,lcm[n]);
    }
    return 0;
}
