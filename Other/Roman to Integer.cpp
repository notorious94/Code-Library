#include<bits/stdc++.h>
using namespace std;

map<char,int>value;

int roman_to_integer(char roman[])
{
    int decimal = 0;
    int len = strlen(roman);

    for(int i=0;i<len-1;i++)
    {
        int s1 = value[roman[i]];
        int s2 = value[roman[i+1]];

        if(s1<s2)
            decimal-=s1;
        else
            decimal +=s1;
    }

    decimal += value[roman[len-1]];

    return decimal;
}

int main()
{

    value['M'] = 1000;
    value['D'] = 500;
    value['C'] = 100;
    value['L'] = 50;
    value['X'] = 10;
    value['V'] = 5;
    value['I'] = 1;

    char roman[MAX];

    cout<<"Roman Number : ";
    cin>>roman;

    int year = roman_to_integer(roman);

    cout<<"\nInteger Equivalent : "<<year<<endl;

    return 0;
}
