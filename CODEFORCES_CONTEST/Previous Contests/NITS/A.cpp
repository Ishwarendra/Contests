#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define int long long

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;
 
    int i = left; /* i is index for left subarray*/
    int j = mid;  /* j is index for right subarray*/
    int k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above explanation/
              diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
     (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
     (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 
/* An auxiliary recursive function that sorts the input
   array and returns the number of inversions in the
   array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array into two parts and call
          _mergeSortAndCountInv() for each of the parts */
        mid = (right + left)/2;
 
        /* Inversion count will be sum of inversions in
           left-part, right-part and number of inversions
           in merging */
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid+1, right);
    }
 
    return inv_count;
}
 
/* This function sorts the input array and returns the
   number of inversions in the array */
int countSwaps(int arr[], int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    std::map<int, int> pos;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != i and a[i] % 2 != i % 2)
        {
            std::cout << "-1\n";
            return;
        }
    }

    int odd[(n + 1) / 2], even[n / 2];
    for (int i = 1, poso = 0, pose = 0; i <= n; ++i)
    {
        if (i % 2)
            odd[poso++] = a[i];
        else
            even[pose++] = (a[i]);
    }
    
    for (int i = 0; i < (n + 1) / 2; i++)
        odd[i] = odd[i] / 2;
    for (int i = 0; i < n / 2; ++i)
        even[i] = even[i] / 2 - 1;

    int x = (n + 1) / 2;
    int y = n / 2;
    std::cout << countSwaps(odd, x) + countSwaps(even, y) << "\n";
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}