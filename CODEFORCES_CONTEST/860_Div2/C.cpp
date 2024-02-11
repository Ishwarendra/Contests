#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i] >> b[i];

    int ans = 1;
    i64 g = 0, l = 1;

    for (int i = 0; i < n; i++)
    {
        g = std::gcd(g, 1LL * a[i] * b[i]);
        l = std::lcm(l, 1LL * b[i]);
        if (g % l == 0)
        {
            g = std::gcd<i64>(g, 1LL * a[i] * b[i]);
            l = std::lcm<i64>(l, b[i]);
        }
        else
        {
            g = 1LL * a[i] * b[i];
            l = b[i];
            ans++;
        }
    }

    std::cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}