#include<bits/stdc++.h>
using namespace std;
const int M = 15000001;

int freq[970704][25];
int cnt[970704];
int maap[M];
int lp[M];
vector<int>prime;

void sieve(int limit = M)
{
    for(int i=2; i<limit; i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            maap[i] = prime.size();
            prime.push_back(i);
        }
        for(int j=0; j<prime.size()&&prime[j]<=i&&i*prime[j]<limit; j++)
            lp[i*prime[j]]=i;
    }
    lp[0] = lp[1] = -1;
}

void pf(int n)
{
    int c = prime.size();
    for(int i=0; i<c&&prime[i]<=n&&lp[n]!=n; i++)
    {
        if(n%prime[i]==0)
        {
            int f = 0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                f++;
            }
            freq[i][f]++;
        }
    }
    if(lp[n]==n)
        freq[maap[n]][1]++;
}

void pf_g(int n)
{
    int c = prime.size();
    for(int i=0; i<c&&prime[i]<=n&&lp[n]!=n; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt[i]++;
            }
        }
    }
    if(lp[n]==n)
        cnt[maap[n]]++;
}


int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    sieve();
    int n,x,g = 0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        g = __gcd(g,x);
        pf(x);
    }

    pf_g(g);

    int c = prime.size();

    for(int i=0; i<c; i++)
        for(int j=23; j>=0; j--)
            freq[i][j]+=freq[i][j+1];

    int ans = n;

    for(int i=0; i<c; i++)
    {
        int k = cnt[i]+1;
        int koto = freq[i][k];
        ans = min(ans,n-koto);
    }

    if(ans==n)
        ans = -1;

    cout<<ans<<endl;

    return 0;
}
