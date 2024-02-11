#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll maxi = max({a, b, c});
    if (a == b and b == c)
    {
        cout << "1 1 1\n";
        return;
    }

    if (a == b and b == maxi)
    {
        cout << 1 << " " << 1 << " " << maxi - c + 1 << "\n";
        return;
    }
    else if (b == c and b == maxi)
    {
        cout << maxi - a + 1 << " " << 1 << " " << 1 << "\n";
        return;
    }
    else if (a == c and a == maxi)
    {
        cout << 1 << " " << maxi - b + 1 << " " << 1 << "\n";
        return;
    }

    if (maxi == a)
        a++;
    else if (maxi == b)
        b++;
    else if (maxi == c)
        c++;
    cout << (maxi - a + 1) << " " << abs(maxi - b + 1) << " " << abs(maxi - c + 1) << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}