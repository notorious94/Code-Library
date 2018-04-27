#include<bits/stdc++.h>
using namespace std;

int parent[1000000], _rank[1000000];

void setValue(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i; /// Representing Himself
        _rank[i] = 1; /// Only 1 element
    }
}

int Find(int a) /// with Path Compression
{
    return (parent[a]==a) ? a : parent[a] =  Find(parent[a]);
}

void makeUnion(int a, int b)
{
    int u = Find(a); /// Finding Parent
    int v = Find(b);

    if(u==v) /// Same Parent
        return;
    if(_rank[u]>=_rank[v]) /// Parsing With Big Tree
    {
        parent[v] = u;
        _rank[u] += _rank[v];
    }
    else
    {
        parent[u] = v;
        _rank[v] += _rank[u];
    }
}

int main()
{
    int n = 5;

    setValue(n);

    makeUnion(0,1);
    makeUnion(2,4);
    makeUnion(3,2);
    makeUnion(1,2);

    for(int i=0;i<n;i++)
        printf("Parent of %d --> %d\n",i, Find(i));

    return 0;
}
