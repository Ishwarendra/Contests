#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void print(vector<pair<ll, int>> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].first << " " << a[i].second << "\n";
    }
}

int getInvCount(vector<pair<ll, int>> arr, int left, int right)
{
    int n = right - left;
    int inv_count = 0;
    for (int i = left + 1; i < right; i++)
        for (int j = i - 1; j >= left; j--)
            if (arr[i].first > arr[j].first)
                inv_count++;

    return inv_count;
}

bool custom_cmp(pair<ll, int> &a, pair<ll, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<ll, int>> a(n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[m * i + j].first;
            a[m * i + j].second = m * i + j;
        }
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        sort(a.begin() + (m * i), a.begin() + (m * (i + 1)), custom_cmp);
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (a[i * m + k].second < a[i * m + j].second)
                    ans++;
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
