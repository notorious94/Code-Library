#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

class edge{
public:
    int u,v,w;
    edge(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    };
    bool operator < (const edge &p) const {
        return  w < p.w;
    }
};

int parent[MAX],_rank[MAX];
vector<edge>edgeList;

void init(int node)
{
    for(int i=0;i<node;i++)
    {
        parent[i] = i;
        _rank[i] = 1;
    }
}

void input(int edges)
{
    int x,y,z;
    while(edges--)
    {
        scanf("%d%d%d",&x,&y,&z);
        edgeList.push_back(edge(x,y,z));
    }
}

int Find(int a)
{
    return (parent[a] == a) ? a : parent[a] = Find(parent[a]);
}

bool makePair(int a, int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u==v)    return false;
    if(_rank[u]>=_rank[v])
    {
        parent[v] = u;
        _rank[u] += _rank[v];
    }
    else
    {
        parent[u] = v;
        _rank[v] += _rank[u];
    }
    return true;
}

void Kruskal(int nodes, int edge)
{
    sort(edgeList.begin(),edgeList.end());
    int sum = 0, taken = 0;
    for(int i=0;i<edge;i++)
    {
        int a = edgeList[i].u;
        int b = edgeList[i].v;
        if(makePair(a,b))
        {
            sum += edgeList[i].w;
            taken++;
            if(taken==nodes-1)  break;
        }
    }
    cout<<"MST : "<<sum<<endl;
}

int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        init(n);
        input(e);
        Kruskal(n,e);
    }
    return 0;
}
