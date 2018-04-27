#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 100001
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int a[MAX],tree[4*MAX];

void build(int n, int b, int e)
{
    if(b==e)
    {
        tree[n]=a[b];
        return;
    }

    int l = 2*n;
    int r = 2*n + 1;
    int m = (b + e)/2;

    build(l,b,m);
    build(r,m+1,e);

    tree[n] = tree[l] + tree[r];

}

int query(int n, int b, int e, int i, int j)
{
    if(i>e||j<b)
        return 0;

    if(b >= i && e <= j)
        return tree[n];

    int l = 2*n;
    int r = 2*n+1;
    int m = (b+e)/2;

    return query(l,b,m,i,j) + query(r,m+1,e,i,j);
}

void update(int n,int b, int e, int i, int newvalue)
{
    if(i>e || i<b)
        return;

    if(b >= i && e <= i)
    {
        tree[n] = newvalue;
        return;
    }

    int l = 2*n;
    int r = 2*n+1;
    int m = (b+e)/2;

    update(l, b, m, i, newvalue);
    update(r, m + 1, e, i, newvalue);

    tree[n] = tree[l] + tree[r];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,q,c,i,v,j;

    sf("%d", &t);

    for(int case_no=1;case_no<=t;case_no++)
    {
        pf("Case %d:\n",case_no);

        sf("%d%d",&n,&q);

        for(int i=1;i<=n;i++)
            sf("%d",&a[i]);

        build(1,1,n);

        while(q--)
        {
            sf("%d",&c);

            if(c==1)
            {
                sf("%d",&i);
                pf("%d\n",a[i+1]);
                a[i+1]=0;
                update(1,1,n,i+1,0);
            }
            else if(c==2)
            {
                sf("%d%d",&i,&v);
                a[i+1]+=v;
                update(1,1,n,i+1,a[i+1]);
            }
            else
            {
                sf("%d%d",&i,&j);
                pf("%d\n",query(1,1,n,i+1,j+1));
            }
        }

    }
    return 0;
}
