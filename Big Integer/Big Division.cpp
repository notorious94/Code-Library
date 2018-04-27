#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool divide(string n, ll d);

int main()
{
    string number;
    ll dividend;
    printf("Input the Number : ");
    cin>>number;
    printf("Input Dividend : ");
    cin>>dividend;
    if(divide(number, dividend)==true)
        cout<<"Possible\n";
    else
        cout<<"Not Possible\n";
    return 0;
}

bool divide(string n, ll d)
{
    int x=0;
    for(int i=0;i<n.size();i++)
    {
        x=x*10+n[i]-'0';
        x%=d;
    }
    if(x==0)
        return true;
    else
        return false;
}
