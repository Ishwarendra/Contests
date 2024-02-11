#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int d;
    cin >> d;

    if (d == 0)
        cout << "Y 0.0 0.0\n";

    else if (d < 4)
        cout << "N\n";
    else
    {
        double Disc = sqrt(d * (long)(d - 4));
        double a = (d + Disc) / 2.0;
        double b = (d - Disc) / 2.0;

        cout << "Y " << setprecision(10) << fixed << a << " " << b << "\n";
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