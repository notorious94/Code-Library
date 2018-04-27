#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

int co_prime(int n)
{
    int ans = n;
    int root = sqrt(n);

    for(int i=2;i<=root;i++)
    {
        if(i>n)
            break;

        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            ans = ans - (ans / i);
        }
    }

    if(n>1)
        ans = ans - (ans/n);

    return ans;
}

int main()
{
    int number, answer;

    cout<<"\nInsert a Number : ";
    cin>>number;

    answer = co_prime(number);

    cout<<"\nNumber of Co Prime for "<<number<<" is "<<answer<<endl;

    return 0;
}
