#include<bits/stdc++.h>
using namespace std;

#define MAX 100001

int ara[MAX];

struct
{
    int prop,sum;
}tree[MAX*3];

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].sum = ara[b];
        return;
    }

    int left  = 2*node;
    int right = 2*node + 1;
    int mid   = (b+e)/2;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int b, int e, int i, int j, int carry=0)
{
    if(i>e||j<b)
        return 0;

    if(b>=i&&e<=j)
        return tree[node].sum + carry*(e-b+1);

    int left  = 2*node;
    int right = 2*node + 1;
    int mid   = (b+e)/2;

    int p1 = query(left, b, mid, i, j, carry+tree[node].prop);
    int p2 = query(right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}

void update(int node, int b, int e, int i, int j, int value)
{
    if(i>e||j<b)
        return;

    if(b>=i&&e<=j)
    {
        tree[node].prop += value;
        tree[node].sum += (value*(e-b+1));
        return;
    }

    int left  = 2*node;
    int right = 2*node + 1;
    int mid   = (b+e)/2;

    update(left, b, mid, i, j, value);
    update(right, mid+1, e, i, j, value);

    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

int main()
{
    while(1)
    {
        int n;
        cout<<"How many Data ?: ";
        cin>>n;

        if(!n)
        {
            cout<<"\nExiting Program....\n\n";
            break;
        }

        cout<<"\nInsert "<<n<<" Data\n\n";

        for(int i=1;i<=n;i++)
            cin>>ara[i];

        build(1,1,n);

        int i,j,v;

        cout<<"\nRange : ";
        cin>>i>>j;

        cout<<"\nQuery Result "<<query(1,1,n,i,j)<<endl;

        cout<<"\nUpdate Range : ";
        cin>>i>>j;
        cout<<"\nValue : ";
        cin>>v;

        update(1,1,n,i,j,v);
        cout<<"\nResult After Update from Range "<<i<<" to "<<j<<" "<<query(1,1,n,1,n)<<endl;

    }
    return 0;
}
