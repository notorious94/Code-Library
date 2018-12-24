
/**

The idea is to traverse array from left to right keeping two variables
minVal and maxVal which represents the minimum and maximum product value
till the i'th index of the array. Now, if the i'th element of the array
is negative that means now the values of minVal and maxVal will be
swapped as value of maxVal will become minimum by multiplying it with a
negative number. Now, compare the minVal and maxVal.

*/

/// The value of minVal and maxVal depends on the current index element or
/// the product of the current index element and the previous minVal and maxVal respectively.

/// Time Complexity - O(n)
/// Space Complexity - O(1)

//Below is the implementation of above approach: C++

#include <bits/stdc++.h>
using namespace std;

// Function to find maximum product subarray
int maxProduct(int* arr, int n)
{
    // Variables to store maximum and minimum
    // product till ith index.
    int minVal = arr[0];
    int maxVal = arr[0];

    int maxProduct = arr[0];

    for (int i = 1; i < n; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}

// Driver Code
int main()
{
    int arr[] = { -1, -3, -10, 0, 60 };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray product is "
         << maxProduct(arr, n) << endl;

    return 0;
}
