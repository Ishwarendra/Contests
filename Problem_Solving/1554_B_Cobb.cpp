#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;

void Cobb()
{
    int n, k;
    cin >> n >> k;
    vi a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = LONG_LONG_MIN;

    if (n < 202)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cur_exp = (i + 1) * (j + 1) - k * (a[i] | a[j]);
                ans = max(ans, cur_exp);
            }
        }
    }

    else
    {
        for(int i = n - 202; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int cur_exp = (i + 1) * (j + 1) - k * (a[i] | a[j]);
                ans = max(ans, cur_exp);
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--)
        Cobb();
    return 0;
}
