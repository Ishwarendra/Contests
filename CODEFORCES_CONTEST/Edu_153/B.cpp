#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int m, k, a1, ak;
    std::cin >> m >> k >> a1 >> ak;

    int ans = 0;

    int need = m % k;
    m -= need;
    if (need > a1)
        ans += need - a1, a1 = 0;
    else
        a1 -= need;

    assert(m % k == 0);
    if (a1 >= m)
        m = 0;
    else
        m = std::max(0, m - (a1 / k) * k);

    m -= 1LL * k * std::min(ak, m / k);
    assert(m >= 0);

    ans += m / k;
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}