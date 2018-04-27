#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

int price[1001],weight[1001];
int dp[1001][1001];
int CAP, N;

int knapsack(int i, int w=0)
{
    if(i==N+1)  return 0;

    if(dp[i][w]!=-1)
        return dp[i][w];

    int cost1 = 0, cost2 = 0;

    if(w+weight[i]<=CAP)
        cost1 = price[i] + knapsack(i+1, w+weight[i]);

    cost2 = knapsack(i+1,w);

    return dp[i][w] = max(cost1,cost2);
}
int main()
{

    printf("Number of Elements : ");
    scanf("%d", &N);

    printf("\nPrice Weight\n\n");

    for(int i=1;i<=N;i++)
        scanf("%d%d", &price[i], &weight[i]);

    printf("\nCapacity : ");
    scanf("%d", &CAP);

    memset(dp, -1, sizeof dp);

    int profit = knapsack(1);

    printf("Max Profit : %d\n",profit);

    return 0;
}
