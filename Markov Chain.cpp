#include<bits/stdc++.h>
using namespace std;
double x[50][50],ans[50][50];
double p[50][50],pk[50][50],pk1[50][50];

int main()
{
    //freopen("in.txt","r",stdin);
    int m,n,K;
    cin>>m>>n;
    for(int i=1;i<=m;i++)   cin>>x[1][i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>p[i][j];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                pk[i][j] += p[i][k]*p[k][j];
    cin>>K;
    K-=2;
    while(K--)
    {
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++)
                    pk1[i][j] += pk[i][k]*p[k][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                pk[i][j] = pk1[i][j];
        memset(pk1,0,sizeof(pk1));
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[1][i]+=x[1][j]*pk[j][i];

    for(int i=1;i<=n;i++)
        cout<<ans[1][i]<<" ";
    cout<<endl;

    return 0;
}
