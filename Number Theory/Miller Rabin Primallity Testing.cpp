#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull mulmod(ull a, ull b, ull c)
{
	ull x = 0,y=a%c;
	while(b>0)
    {
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b >>= 1;
	}
	return x;
}

ull power(ull a, ull b, ull c)
{
	ull x = 1, y = a;
	while(b>0)
    {
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b >>= 1;
	}
	return x;
}

bool Miller_Rabin(ull Prime,ull iter=1)
{
    if(Prime<=1)            return false;
    if(Prime==2||Prime==3)  return true;
    if(Prime%2==0)          return false;
    for(int i=1;i<=1;i++)
    {
        ull a = 2 + rand()%(Prime-4);
        if(power(a,Prime-1,Prime)!=1)
            return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll P,Test;
    cin>>Test;
    while(Test--)
    {
        cin>>P;
        if(Miller_Rabin(P))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
