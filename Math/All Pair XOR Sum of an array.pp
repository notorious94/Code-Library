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
/*
Explanation :  arr[] = { 7, 3, 5 }
7 = 1 1 1
3 = 0 1 1
5 = 1 0 1
For bit position 0 : 
Bits with zero = 0
Bits with one = 3
Answer = 0 * 3 * 2 ^ 0 = 0
Similarly, for bit position 1 :
Bits with zero = 1
Bits with one = 2
Answer = 1 * 2 * 2 ^ 1 = 4
Similarly, for bit position 2 :
Bits with zero = 1
Bits with one = 2
Answer = 1 * 2 * 2 ^ 2 = 8
 Final answer = 0 + 4 + 8 = 12 
 */
