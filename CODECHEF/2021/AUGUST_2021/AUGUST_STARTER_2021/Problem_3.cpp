#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for(int i = 0; i < k; i++)
    {
        if (a[i] >= 0)
            break;
        a[i] = a[i]*(-1);
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
            continue;
        sum += a[i];
    }

    cout << sum << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}