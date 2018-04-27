#include<bits/stdc++.h>
using namespace std;
string sum(string a, string b)
{
    string r;
    if(a.size()>b.size())
        swap(a, b);
    reverse(a.begin(),a.end());
    reverse(b.begin(), b.end());
    int carry=0, sum=0;
    for(int i=0;i<a.size();i++)
    {
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        r.push_back(sum%10+'0');
        carry=sum/10;
    }
    for(int i=a.size();i<b.size();i++)
    {
        sum=(b[i]-'0')+carry;
        r.push_back(sum%10+'0');
        carry=sum/10;
    }
    if(carry)
        r.push_back(carry+'0');
    reverse(r.begin(), r.end());
    return r;
}
int main()
{
    string a, b, result;
    printf("Enter first number  : ");
    cin>>a;
    printf("Enter second number : ");
    cin>>b;
    result=sum(a,b);
    cout<<result<<endl;
    return 0;
}
