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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

// Matrix Multiplication Function
void multiply(ull mat_1[2][2],ull mat_2[2][2])
{
    ull r[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ull sum = 0;
            for(int k=0;k<2;k++)
            {
                sum += (mat_1[i][k]%MOD * mat_2[k][j]%MOD);
                sum %=  MOD;
            }
            r[i][j] = sum;
        }
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            mat_1[i][j] = r[i][j];
}

void Expo(int p,ull matrix[2][2])
{
    if(p==0||p==1)  return;
    ull temp[2][2] = {{1,1},{1,0}}; // for Fibonacci Series Only
    Expo(p/2,matrix);// Divide and Conquer
    multiply(matrix,matrix);
    if(p&1) multiply(matrix,temp); // Odd Power
}

ull Fibonacci(int n)
{
    if(!n)  return 0;
    ull Fibo[2][2] = {{1,1},{1,0}};
    Expo(n-1,Fibo);
    return Fibo[0][0] % MOD;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(true)
    {
        printf("N : ");
        scanf("%d",&n);
        if(n<0) break;
        printf("Fib[%d] = %llu\n",n,Fibonacci(n));
    }
    return 0;
}
