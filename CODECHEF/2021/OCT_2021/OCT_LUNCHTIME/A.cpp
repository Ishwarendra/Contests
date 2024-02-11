#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

ull power(ull x, ull y)
{
     
    // Initialize answer
    ull res = 1;
     
    // Check till the number becomes zero
    while (y)
    {
         
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
             
        // y = y/2
        y = y >> 1;
         
        // Change x to x^2
        x = (x * x);
    }
    return res;
}

vector<ull> make_array(int n)
{
    vector<ull> arr(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        arr[i] = power(2, i);
    }

    arr[n - 1] = power(2, n - 2);
    arr[n] = power(2, n - 2) + 1;

    sort(arr.begin(), arr.end());
    return arr;
}

void solve()

{
    int n; cin >> n;
    if (n == 1)
    {
        cout << "1 1\n";
        return;
    }

    if (n == 2)
    {
        cout << "1 1 2\n";
        return;
    }
    vector<ull> ans = make_array(n);
    for(ull i : ans)
        cout << i << " ";
    cout << "\n";

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}