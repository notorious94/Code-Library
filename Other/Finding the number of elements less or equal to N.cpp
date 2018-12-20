#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll>a;
vector<int> :: iterator it;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,m,x,id;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        id = upper_bound(a.begin(),a.end(),x)-a.begin();
        printf("%d ",id);
    }
    return 0;
}
