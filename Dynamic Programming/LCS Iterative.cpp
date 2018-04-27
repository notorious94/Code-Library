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

int dp[1000][1000];
string a,b;

int lcs()
{
    int _max = 0;
    for(int i=1;a[i];i++)
    {
        for(int j=1;b[j];j++)
        {
            if(a[i]==b[j])
                dp[i][j] = 1 + dp[i-1][j-1];

            else
            {
                if(dp[i-1][j]>=dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[a.size()-1][b.size()-1];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while(get_stl(a))
    {
        get_stl(b);
        a = " " + a;
        b = " " + b;
        memset(dp,0,sizeof(dp));
        cout<<lcs()<<endl;
    }

    return 0;
}
