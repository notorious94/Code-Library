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
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

vector<int>top,Graph[1005],Transpose[1005],temp;
bool visit[1005];

void init(int n)
{
    mem(visit,false);
    top.clear();
    temp.clear();
    for(int i=0; i<=n; i++)
    {
        Transpose[i].clear();
        Graph[i].clear();
    }
}

void edge(int m)
{
    int u,v;
    while(m--)
    {
        cin>>u>>v;
        Graph[u].push_back(v);
        Transpose[v].push_back(u);
    }
}

int printComponent(int scc)
{
    sort(all(temp));
    cout<<"SCC "<<++scc<<" -> (" ;
    for(int j=0; j<temp.size(); j++)
        cout<<" "<<(char)(temp[j]-1+'A');
    cout<<" )"<<endl;
    return scc;
}

void DFS_1(int s)
{
    visit[s] = true;
    for(int i=0; i<Graph[s].size(); i++)
        if(!visit[Graph[s][i]])
            DFS_1(Graph[s][i]);
    top.push_back(s);
}

void call_1(int n)
{
    for(int i=1; i<=n; i++)
        if(!visit[i])
            DFS_1(i);
}

void DFS_2(int s)
{
    visit[s] = true;
    for(int i=0; i<Transpose[s].size(); i++)
        if(!visit[Transpose[s][i]])
            DFS_2(Transpose[s][i]);
    temp.push_back(s);
}

void call_2(int n)
{
    mem(visit,false);
    int scc = 0;
    for(int i=n-1; i>=0; i--)
    {
        int v = top[i];
        if(!visit[v])
        {
            temp.clear();
            DFS_2(v);
            scc = printComponent(scc);
        }
    }
}

int main()
{
    freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n,m;
    cin>>n>>m;
    init(n);
    edge(m);
    call_1(n);
    call_2(n);
    return 0;
}

/*

Input:

11 13
1 2
2 3
3 1
2 4
4 5
5 6
6 4
7 6
7 8
8 9
9 10
10 7
10 11

*/
