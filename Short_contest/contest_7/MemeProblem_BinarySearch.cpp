#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    long double d;
    cin >> d;
    if (d == 0)
        cout << "Y 0 0\n";
    else if (d < 4)
        cout << "N\n";
    else
    {
        cout << "Y ";
        long double ans = (long double)d / 2;
        long double l = 0, r = d;
        for (int i = 0; i < 100; i++)
        {
            long double mid = (long double)(r + l) / 2.0;
            long double some = (long double)d / mid;
            if (some <= d - mid)
            {
                ans = mid;
                r = mid;
            }
            else
                l = mid;
        }
        cout << fixed << setprecision(9) << (d - ans) << " " << (ans) << "\n";
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}