#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, g;
    std::cin >> n >> k >> g;

    i64 total = 1LL * k * g;
    auto tot = total;
    int limit = (g + 1) / 2 - 1;

    if (n == 1)
    {
        int r = tot % g;
        if (r > limit)
            std::cout << 0 << "\n";
        else
            std::cout << tot - (tot / g) * g << "\n";

        return;
    }

    if (tot <= (n - 2LL) * limit)
        std::cout << tot << "\n";
    else
    {
        tot -= (n - 2LL) * limit;
        int r = tot % g;
        int sub = std::min(r, limit);
        r -= sub;
        tot -= sub;

        if (r > limit)
            tot = tot + g - r;
        else
            tot = tot - r;            

        std::cout << total - tot << "\n";
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