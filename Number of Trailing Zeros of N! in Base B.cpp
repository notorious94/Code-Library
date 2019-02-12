// Tutorial: http://mathforum.org/library/drmath/view/55723.html?fbclid=IwAR1Amus_cKiYu_6-3kgXXfTR8ArqszjRq_-cUskCBQdCRQpZkNR-VkIfTnM

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>facto;
map<ll,ll>freq;

ll mark[1000005];
vector<ll>prime;

void sieve(int range = 1000000)
{
    for(int i=2;i<=range;i++)
    {
        if(!mark[i])
        {
            mark[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=range&&prime[j]<=i;j++)
            mark[i*prime[j]]=prime[j];
    }
}

void factorize(ll n)
{
    sieve();
    ll r = sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=r;i++)
    {
        if(n%prime[i]==0)
        {
            int f = 0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                f++;
            }
            facto.push_back(prime[i]);
            freq[prime[i]]=f;
        }
    }
    if(n>1)
    {
        facto.push_back(n);
        freq[n]++;
    }
}

void trailingZero(ll n,ll base)
{
    factorize(base);
    ll noz = n;
    for (int i=0;i<facto.size();i++)
    {
        ll c = 0, temp = n;
        while (temp / facto[i] > 0)
        {
            c += temp / facto[i];
            temp /= facto[i];
        }
        noz = min(noz, c / freq[facto[i]]);
    }
    cout<<noz<<endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll n,base;
    cin>>n>>base;
    trailingZero(n,base);
    return 0;
}
