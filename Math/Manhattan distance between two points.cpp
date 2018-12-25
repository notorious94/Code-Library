/// Manhattan distance
/// Formula |x1-x2| + |y1-y2|
#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main()
{
    int x1,x2,y1,y2;

    cin>>x1>>y1>>x2>>y2;

    int dist = abs(x1-x2)+abs(y1-y2);

    cout<<dist<<endl;

    return 0;
}
