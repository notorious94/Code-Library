#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

void fact(int n)
{
    string f;
    f.push_back('1');

    int carry;

    for(int i=2;i<=n;i++)
    {
        carry=0;
        for(int j=0;j<f.size();j++)
        {
            carry += (f[j]-48)*i;
            f[j] = (carry%10) + 48;
            carry /= 10;
        }
        while(carry)
        {
            f.push_back((carry%10)+48);
            carry/=10;
        }
    }

    pf("\nFactorial of %d is:\n\n",n);

    for(int i=f.size()-1;i>=0;i--)
        pf("%c",f[i]);

    pf("\n\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(1)
    {
        pf("Enter a number ( -1 to Exit ) : ");
        sif(n);
        if(n==-1)
        {
            pf("\nExiting Program .....\n");
            break;
        }
        fact(n);
    }
    return 0;
}
