#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

bool overlap(ld x1, ld y1, ld x2, ld y2)
{
    return ((x2 <= y1 and x2 >= x1) or (y2 <= y1 and y2 >= x1));
}

void solve()
{
    int n; cin >> n;
    vector<pair<ld, ld>> interval(n);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x >> interval[i].first >> interval[i].second;
        if (x == 2)
            interval[i].second -= 0.000001;
        else if (x == 3)
            interval[i].first += 0.0000001;
        else if (x == 4)
            interval[i].first += 0.0000001, interval[i].second -= 0.000001;
    }

    sort(interval.begin(), interval.end());

    ll ans = 0LL;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if (overlap(interval[i].first, interval[i].second, interval[j].first, interval[j].second))
                ans++;
        }
    }

    cout << ans << "\n";

}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}