// Segmented Sieve
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAX = INT_MAX;
const int root = sqrt(MAX);

int lp[root+1];
bool isPrime[100001];
vector<ll>primes;

void sieve()
{
/**
    Generates all the primes up to root of RANGE
    Complexity --> O(n)
*/
    lp[0] = lp[1] = -1;
    for(int i=2;i<=root;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j=0;j<primes.size()&&primes[j]<=i&&i*primes[j]<=root;j++)
            lp[i*primes[j]] = i;
    }
}

void segSieve(ll left,ll right)
{
    int total = right-left+1,prime = 0;

    /// Considering all the numbers are Prime
    for(int i=0;i<total;i++)
        isPrime[i] = true;

    if(left==1) /// Corner Case
        isPrime[0] = false;

    /// Segment Sieve
    for(int i=0;i<primes.size()&& primes[i]*primes[i]<=right;i++)
    {
        int currentPrime = primes[i];

        ll base = (left/currentPrime)*currentPrime;

        if(base<left)   base+=currentPrime; /// Making sure base falls in Range

        for(ll j=base;j<=right;j+=currentPrime)
            isPrime[j-left] = false;

        if(base==currentPrime) /// if base itself is a Prime
            isPrime[base-left] = true;
    }

    for(int i=0;i<total;i++)
        if(isPrime[i])
            cout<<i+left<<endl;

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();
    int test,kase = 1;
    ll left,right;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld%lld",&left,&right);
        segSieve(left,right);
    }
    return 0;

}
