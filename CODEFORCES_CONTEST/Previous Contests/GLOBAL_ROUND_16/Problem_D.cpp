#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int getInvCount(vector<ll> arr, int n)
{
    int inv_count = 0;
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0; j--)
            if (arr[i] > arr[j])
                inv_count++;
 
    return inv_count;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);

    for (ll &x : a)
        cin >> x;

    cout << getInvCount(a, m) << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}