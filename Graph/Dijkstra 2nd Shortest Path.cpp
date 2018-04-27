#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

/// M A C R O Ends here

class edge
{
public:
    int n, w;
    edge(int node, int weight)
    {
        n = node;
        w = weight;
    }
};

class node
{
public:
    int n,w;
    node(int nd, int c)
    {
        n = nd;
        w = c;
    }
    bool operator < (const node &p)const
    {   return w>p.w;   }
};

vector<edge>graph[5001];
vector<ll>dist[5001];

void reset(int node)
{
    for(int i=1;i<=node;i++)
    {
        graph[i].clear();
        dist[i].clear();
    }
}

void input(int e)
{
    ll a,b,c;
    while(e--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        graph[a].push_back(edge(b,c));
        graph[b].push_back(edge(a,c));
    }
}

void Dijkstra(int s, int d)
{
    priority_queue<node>Q;
    Q.push(node(s,0));

    while(Q.size())
    {
        node T = Q.top();
        Q.pop();

        int u = T.n;
        int w = T.w;

        if(dist[u].size()==0)       dist[u].push_back(w);
        else if(dist[u].back()!=w)  dist[u].push_back(w);
        if(dist[u].size()>2)        continue;

        for(int i=0;i<graph[u].size();i++)
        {
            edge e = graph[u][i];
            int v = e.n;
            if(dist[v].size()==2)   continue;
            int curr_dist = e.w + w;
            Q.push(node(v,curr_dist));
        }
    }
    pf("%lld\n",dist[d][1]);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,e,test;

    scanf("%d",&test);

    for(int kase=1;kase<=test;kase++)
    {
        scanf("%d%d",&n,&e);
        reset(n);
        input(e);
        pf("Case %d: ",kase);
        Dijkstra(1,n);
    }

    return 0;
}
