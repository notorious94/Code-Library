#include<bits/stdc++.h>
using namespace std;

int capacity[101][101];
int parent[101];
bool visit[101];
int node,edge;

bool isPath(int s,int d)
{
    queue<int>q;
    memset(visit,false,sizeof(visit));
    memset(parent,-1,sizeof(parent));
    q.push(s);
    visit[s] = true;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int v=1;v<=node;v++)
        {
            if(!visit[v] && capacity[u][v] > 0)
            {
                visit[v] = true;
                parent[v] = u;
                q.push(v);
                if(v==d)    return true;
            }
        }
    }
    return false;
}

int fordFulkerson(int source,int sink)
{
    int maxFlow = 0;
    while(isPath(source,sink))
    {
        int v = sink,u;
        int min_res_cap = INT_MAX;
        while(parent[v]!=-1)
        {
            u = parent[v];
            min_res_cap = min(min_res_cap,capacity[u][v]);
            v = parent[v];
        }
        v = sink;
        while(parent[v]!=-1)
        {
            u = parent[v];
            capacity[u][v] -= min_res_cap;
            capacity[v][u] += min_res_cap;
            v = parent[v];
        }
        maxFlow+=min_res_cap;
    }
    return maxFlow;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int source,sink;
    cin>>node>>edge;
    cin>>source>>sink;

    while(edge--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        capacity[u][v] = c;
    }

    cout<<"Maximum Possible Flow: "<<fordFulkerson(source,sink)<<endl;

    return 0;
}
