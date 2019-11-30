#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;
ll a[N],one[30],zero[30];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(ll j=29;j>=0;j--)
        {
            if(a[i]&(1<<j)) one[j]++;
            else            zero[j]++;
        }
    }
    ll ans = 0;
    for(ll i=29;i>=0;i--)
        ans += one[i]*zero[i]*(1<<i);
    cout<<ans<<endl;
    return 0;
}
