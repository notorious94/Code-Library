#include<bits/stdc++.h>
using namespace std;

vector<int>g[105];
int deg[105];

void topSort(int node)
{
    queue<int>q;

    for(int i = 0; i < node; i++)
        if(deg[i]==0)
            q.push(i);
    
    while(q.size())
    {
        int u = q.front();
        cout<<u<<" -> ";
        q.pop();

        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            deg[v]--;
            if(deg[v] == 0)
            {
                q.push(v);
            }
        }
    }

}

int main()
{

    int node,edge;
    
    cout<<"How many nodes? ";
    cin>>node;
    
    cout<<"How many edges? ";
    cin>>edge;

    int u,v;

    while(edge--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        deg[v]++;
    }

    topSort(node);

    return 0;

}
