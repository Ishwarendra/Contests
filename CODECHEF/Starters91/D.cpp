#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int power2(auto x)
{
    return (x & (x + 1)) == 0;
}

void solve()
{
    i64 l, r;
    std::cin >> l >> r;

    if (power2(r))
    {
        std::cout << r + 1 << "\n";
        return;
    }

    i64 p = std::__lg(r) + 1;
    r = 1LL << p;
    if (l == 0)
        std::cout << r << "\n";
    else
    {
        i64 cur = 1, ans = 0;
        while (cur < l)
            cur *= 2;

        while (cur < r)
        {
            ans += cur - l;
            cur *= 2;
        }

        std::cout << ans << "\n";
    }
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