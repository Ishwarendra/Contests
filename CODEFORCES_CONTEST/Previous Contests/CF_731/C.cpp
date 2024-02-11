#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
typedef vector<int> vi;

void solve()
{
    int k, n, m;
    cin >> k >> n >> m;
    vi mono(n), poly(m), ans;

    for (int i = 0; i < n; i++)
        cin >> mono[i];

    for (int i = 0; i < m; i++)
        cin >> poly[i];

    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (mono[i] == 0)
            ans.push_back(0), i++, k++;
        else if (mono[i] <= k)
            ans.push_back(mono[i]), i++;
        else{
        if (poly[j] == 0)
            ans.push_back(0), j++, k++;

        else if (poly[j] <= k)
            ans.push_back(poly[j]), j++;

        else
        {
            cout << -1 << "\n";
            return;
        }
    }
    }

    while (i < n)
    {
        if (mono[i] == 0)
            ans.push_back(0), i++, k++;

        else if (mono[i] <= k)
            ans.push_back(mono[i]), i++;
        else
        {
            cout << -1 << "\n";
            return;
        }
    }

    while (j < m)
    {
        if (poly[j] == 0)
            ans.push_back(0), j++, k++;

        else if (poly[j] <= k)
            ans.push_back(poly[j]), j++;

        else
        {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    cout << '\n';
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