#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

int _mergeSort(vector<int> arr, vector<int> temp, int left, int right);
int merge(vector<int> arr, vector<int> temp, int left, int mid, int right);

int mergeSort(vector<int> arr, int array_size)
{
    vector<int> temp(array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(vector<int> arr, vector<int> temp, int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(vector<int> arr, vector<int> temp, int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> stru(n);
    for(int i = 0; i < n; i++)
        cin >> stru[i];
    
    sort(stru.begin(), stru.end());

    vector<int> v;

    for(string s : stru)
    {
        for(char ch : s)
        {
            v.push_back(ch - '0');
        }
    }

    cout << mergeSort({0, 1, 0, 1, 0}, 5) << "\n";
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    // vector<int> arr {1, 20, 6, 4, 5 };
    // cout << mergeSort(arr, 5);
    // vector<string> v{"10", "01", "00"};
    // sort(v.begin(), v.end());
    // cout << v[0] << " " << v[1] << " " << v[2];
    return 0;
}