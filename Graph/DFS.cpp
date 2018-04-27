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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

/// M A C R O Ends here

vector<int>graph[10000];
int visited[10003];
int d[10003], f[10003];
int parent[10003];
int ti;

void DFS_Visit(int node)
{
    visited[node] = 1;
    ti = ti + 1;
    d[node] = ti;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(visited[graph[node][i]]==0)
        {
            parent[graph[node][i]] = 1;
            DFS_Visit(graph[node][i]);
        }
        else if(visited[graph[node][i]]==1)
            printf("Got a Cycle\n");
    }

    visited[node] = 2;
    ti = ti + 1;
    f[node] = ti;

    return;
}


void DFS(int node, int edge)
{
    for(int i=0; i<=node; i++)
    {
        visited[i] = 0;
        parent[i] = i;
    }
    ti = 0;
    for(int i=1; i<=node; i++)
        if(visited[i] == 0)
            DFS_Visit(i);
    return;
}

int main()
{
   int node, edge, u, v;
   
   scanf("%d %d", &node, &edge);
   
   for(int i=0; i<edge; i++)
   {
       scanf("%d %d", &u, &v);
       graph[u].push_back(v);
   }

   DFS(node, edge);

   for(int i=1; i<=node; i++)
   {
        printf("Starting time: %d Finishing time: %d\n", d[i], f[i]);
        printf("Parent of %d: %d\n", i, parent[i]);
   }
   return 0;
}
