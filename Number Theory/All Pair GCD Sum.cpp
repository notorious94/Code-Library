/// https://www.geeksforgeeks.org/summation-gcd-pairs-n/
/// Time complexity: O(MAX*log(log MAX))
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 1e6+5;

ull sum[N],phi[N];

int lp[N];
vector<int>prime;

void sieve(int limit = 1e6+1)
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

void eulerPhi()
{
    for(int i=1;i<=1e6;i++)
        phi[i] = i;
    for(auto p : prime)
        for(int j=1;j*p<=1e6;j++)
        {
            phi[j*p]/=p;
            phi[j*p]*=(p-1);
        }
}

void GCDsum()
{
    for(int i=1;i<=1e6;i++)
        for(int j=2;i*j<=1e6;j++)
            sum[i*j] += i*phi[j];
    for(int i=1;i<=1e6;i++)
        sum[i]+=sum[i-1];
}

int main()
{
    sieve();
    eulerPhi();
    GCDsum();
    int n;
    while(cin>>n)
    {
        if(!n)  break;
        cout<<sum[n]<<endl;
    }
    return 0;
}
