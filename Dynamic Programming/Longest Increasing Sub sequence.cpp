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

int main()
{
    int n,value;
    /// n = Array Length
    /// value = value of each element

    vector<int>LIS,arra;

    /// LIS = Array for calculating Longest Increasing Subsequence
    /// arr = normal array

    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            sif(value);

            arra.push_back(value);
            /// Inserting Values

            LIS.push_back(1);
            /// Initializing all element of LIS with 1
            /// as single element represents an increasing subsequence too
        }

        int max=-1;
        /// For counting MAX length

        for(int i=1;i<n;i++) /// Outer Loop
        {
            for(int j=0;j<i;j++) /// Inner Loop
            {
                if(arra[j]<arra[i] && LIS[j]+1>LIS[i])
                {
                    /// Condition 1: Lower value than arra[i] is found on the left side
                    /// Condition 2: Current LIS value of LIS[i] is lower than LIS[j]+1

                    LIS[i]=LIS[j]+1; /// Updating LIS length

                    if(LIS[i]>max)  /// Checking for MAX length value
                        max=LIS[i]; /// if true then updating
                }
            }
        }
        cout << max << endl;
        
        LIS.clear();
        arra.clear(); ///freeing memory
    }
    return 0;
}
