/// Max Length of String is 20

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 26;
ll f[maxn],freq[maxn];

void DP()
{
    f[0]=1;
    for(ll i=1;i<21;i++)
        f[i]=i*f[i-1];
}

bool ok(string s,ll k)
{
    ll p = f[(int)s.size()];
    memset(freq,0,sizeof(freq));
    for(int i=0;s[i];i++)   freq[s[i]-'a']++;
    for(int i=0;i<26;i++)   p/=f[freq[i]];
    return (k<=p);
}

void solve(string s,ll N)
{
    ll sum=0,k=0,l=s.size();

    string ans;

    while(sum!=N)
    {
        sum = 0;
        for(int i=0;i<26;i++)
        {
            if(!freq[i])    continue;
            freq[i]--;
            ll xsum = f[l-1-k];
            for(int j=0;j<26;j++)   xsum/=f[freq[j]];
            sum+=xsum;
            if(sum>=N)
            {
                ans+=(i+'a');
                k++;
                N -= (sum-xsum);
                break;
            }
            else    freq[i]++;
        }
    }

    for(int i=25;i>=0;i--)
        while(freq[i]--)
            ans+=(i+'a');

    cout<<ans<<endl;

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    DP();

    ll test,k;
    string s;

    cin>>test;

    for(int cn=1;cn<=test;cn++)
    {
        cin>>s>>k;
        cout<<"Case "<<cn<<": ";
        if(!ok(s,k))
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        solve(s,k);
    }
    return 0;
}
