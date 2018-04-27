#include<bits/stdc++.h>
#define MAX 500
#define INF INT_MAX

using namespace std;

/// M A C R O Ends here

int graph[MAX][MAX],path[MAX][MAX];

void init(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = (i==j) ? 0 : INF;
            path[i][j] = i;
        }
    }
}

void input(int e)
{
    int a,b,c;
    while(e--)
    {
        cin>>a>>b>>c;
        graph[a][b] = c;
        //graph[b][a] = c; Bidirectional
    }
}

void pathPrint(int s, int d)
{
    if(s==d)
    {
        printf("%d",s);
        return;
    }
    pathPrint(s, path[s][d]);
    printf(" -> %d",d);
}

void FloydWarshall(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(graph[i][k]!=INF && graph[k][j]!=INF){
                    if(graph[i][j]>graph[i][k]+graph[k][j]){
                        graph[i][j] = graph[i][k]+graph[k][j];
                        path[i][j]  = path[k][j];
                    }
                }
}

int main()
{
    int nodes,edges,s,d;
    cin>>nodes>>edges;

    init(nodes);
    input(edges);
    FloydWarshall(nodes);

    cin>>s>>d;

    if(graph[s][d]==INF)
        cout<<"Unreachable"<<endl;

    else
    {
        cout<<"Distance "<<graph[s][d]<<endl;
        cout<<"Path : ";
        pathPrint(s,d);
        cout<<endl;
    }

    return 0;
}
