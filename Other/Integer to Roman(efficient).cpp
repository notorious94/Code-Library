#include<bits/stdc++.h>
using namespace std;

string int_to_roman(int N)
{
    string M[] = {"","M","MM","MMM"};
    string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

    string thousand = M [ N / 1000 ];
    string hundred  = C [ (N%1000) / 100 ];
    string ten      = X [ (N%100) / 10 ];
    string one      = I [ N%10 ];

    string roman = thousand + hundred + ten + one;

    return roman;
}

int main()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;

    cout<<"\nRoman equivalent of "<<n<<" is : "<<int_to_roman(n)<<endl;

    return 0;
}
