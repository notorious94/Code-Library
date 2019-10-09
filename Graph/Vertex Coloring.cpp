#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
map<int,bool>color;

int node_color[1000];

int getColor(int u)
{
    for(auto c : color)
    {
        bool flag = true;
        for(auto v : adj[u])
            if(node_color[v]==c.first)
            {
                flag = false;
                break;
            }
        if(flag)
        {
            node_color[u] = c.first;
            return c.first;
        }
    }
    int x = color.size()+1;
    node_color[u] = x;
    color[x] = true;
    return x;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int n,e,u,v;

    cin>>n>>e;

    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<getColor(i)<<endl;

    cout<<"Chromatic Number "<<(color.size())<<endl;

    return 0;
}
