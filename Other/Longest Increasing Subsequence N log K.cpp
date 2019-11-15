#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

const int N = 1e5+5;

int I[N],A[N];

int _binary_search(int low,int high,int item)
{
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(I[mid]<item) low = mid + 1;
        else            high = mid - 1;
    }
    return low;
}

int LIS_NlogK(int n)
{
    I[0] = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
        I[i] = INF;
    }
    int lisLen = 0;
    for(int i=1;i<=n;i++)
    {
        int loc = _binary_search(0,lisLen,A[i]);
        lisLen = max(lisLen,loc);
        I[loc] = A[i];
    }
    return lisLen;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,LIS;

    cin>>n;
    LIS = LIS_NlogK(n);

    cout<<"Length of longest increasing subsequence: "<<LIS<<endl;

    return 0;
}
