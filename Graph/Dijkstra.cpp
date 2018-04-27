#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 100001
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

/// M A C R O Ends here

/// Adjacency List, Cost, Path_array
vector<int>Adj[MAX+10],Cost[MAX+10],Path;

/// Shortest Distance, Parent_array
int Dist[MAX+10],Parent[MAX+10];

/// Boolean Array for memory saving
bool visit [MAX+10];

class node
{
public:
    int no, weight;
    node(int n, int w)
    {
        no = n;
        weight = w;
    }
    // Compare function for Priority Queue
    bool operator < (const node &p)
    const{
        return weight>p.weight;
    }
};

void reset(int nodes)
{
    /// Clearing List before running a program
    for(int i=0;i<=nodes+2;i++)
    {
        Cost[i].clear();
        Adj[i].clear();
    }
}

int Dijkstra(int nodes, int s, int d)
{
    for(int i=0;i<=nodes+1;i++) /// Initialization
    {
        Parent[i] = -1;
        Dist[i] = INF;
        visit[i] = false;
    }

    Dist[s]=0;
    Parent[s] = -1;

    priority_queue<node>Q;

    Q.push(node(s,0));

    while(Q.size())
    {
        node Top = Q.top();

        Q.pop();

        int u = Top.no;

        /// If its the destination then its already relaxed
        if(u==d)    return Dist[d];

        visit[u] = true;

        for(int i=0;i<Adj[u].size();i++)
        {
            int v = Adj[u][i];
            if(!visit[v])  /// Memory Saving
            {
                if(Dist[v]>Dist[u]+Cost[u][i])
                {
                    Dist[v] = Dist[u]+Cost[u][i]; /// Updating Cost
                    Parent[v] = u;               /// Predecessor
                    Q.push(node(v, Dist[v]));
                }
            }
        }

    }
    return -1;
}

void path_print(int s, int d)
{
    int p = d;
    Path.clear();
    while(p!=-1)
    {
        Path.push_back(p);
        p = Parent[p];
    }
    reverse(Path.begin(), Path.end());
    for(int i=0;i<Path.size();i++)
        printf("%d%c",Path[i],(i==Path.size()-1) ? '\n' : ' ');
}

void input(int edge)
{
    int a,b,c;
    while(edge--)
    {
        scanf("%d%d%d",&a,&b,&c);
        Adj[a].push_back(b);
        Adj[b].push_back(a);
        Cost[a].push_back(c);
        Cost[b].push_back(c);
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b,c;

    scanf("%d%d",&n,&m);

    reset(n);
    input(m);

    int sortest_distance = Dijkstra(n,1,n);

    if(sortest_distance==-1)
        pf("%d\n",sortest_distance);
    else
        path_print(1,n);

    return 0;
}
