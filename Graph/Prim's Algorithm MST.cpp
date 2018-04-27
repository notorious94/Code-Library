#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

class node
{
    public:
        int u,v,w;
    node(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator < (const node &p) const
    {
        return w > p.w;
    }
};

bool visit[MAX];
vector<int>Graph[MAX],Cost[MAX];

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        visit[n] = false;
        Graph[i].clear();
        Cost[i].clear();
    }
}

void input(int e)
{
    int a, b, c;
    while(e--)
    {
        cin>>a>>b>>c;
        Graph[a].push_back(b);
        Cost[a].push_back(c);
        Graph[b].push_back(a);
        Cost[b].push_back(c);
    }
}

int PrimsAlgo(int s, int n)
{
    priority_queue<node>q;

    int edge = 0, mst = 0;
    visit[s] = true;
    for(int i=0;i<Graph[s].size();i++)
        q.push(node(s,Graph[s][i],Cost[s][i]));

    while(q.size())
    {
        int v = q.top().v;
        int w = q.top().w;
        q.pop();
        if(!visit[v])
        {
            visit[v] = true;
            mst+=w;
            if(++edge==n-1)     break;
            for(int i=0;i<Graph[v].size();i++)
                if(visit[Graph[v][i]]==false)
                    q.push(node(v,Graph[v][i],Cost[v][i]));
        }
    }
    cout<<mst<<endl;
    return mst;
}

int main()
{
    int n,e,s;
    cin>>n>>e>>s;
    init(n);
    input(e);
    PrimsAlgo(s,n);
    return 0;
}
