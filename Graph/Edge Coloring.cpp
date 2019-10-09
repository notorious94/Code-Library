#include<bits/stdc++.h>
using namespace std;

map<int,bool>color;
map<int,bool>l[100];
vector<pair<int,int> >edge;
int ans[100];

int getColor(int u,int v)
{
    for(auto c : color)
        if(!l[u][c.first]&&!l[v][c.first])
        {
            l[u][c.first] = l[v][c.first] = true;
            return c.first;
        }
    int newColor = color.size()+1;
    color[newColor] = true;
    l[u][newColor] = l[v][newColor] = true;
    return newColor;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int e,u,v;
    cin>>e;
    while(e--)
    {
        cin>>u>>v;
        edge.push_back({u,v});
    }
    for(int i=0;i<edge.size();i++)
    {
        u = edge[i].first;
        v = edge[i].second;
        ans[i] = getColor(u,v);
        cout<<u<<" "<<v<<" Color "<<ans[i]<<endl;
    }
    return 0;
}
