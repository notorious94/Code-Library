#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

/// M A C R O Ends here

vector<int>adjList[MAX];
int level[MAX],parent[MAX];
bool visit[MAX];

void init(int n)
{
    for(int i=0;i<n;i++)
        adjList[i].clear();
}

void input(int e)
{
    int a,b;
    while(e--)
    {
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

void BFS(int s, int d)
{
    memset(visit, false, sizeof(visit));

    queue<int>Q;

    Q.push(s);
    level[s]  = 0;
    visit[s]  = true;
    parent[s] = -1;

    while(Q.size())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<adjList[u].size();i++)
        {
            int v = adjList[u][i];
            if(visit[v]==false)
            {
                visit[v] = true;
                parent[v] = u;
                level[v] = level[u]+1;
            }
        }
        if(visit[d])    break;
    }

    if(visit[d])
        printf("Distance between %d to %d is : %d\n",s,d,level[d]);
    else
        printf("Not Reachable\n");
}

void pathPrint(int s)
{
    if(s==-1)   return;
    pathPrint(parent[s]);
    printf(" %d ",s);
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    init(nodes);
    input(edges);
    BFS(1,2);
    if(visit[2])    pathPrint(2);

    return 0;
}
