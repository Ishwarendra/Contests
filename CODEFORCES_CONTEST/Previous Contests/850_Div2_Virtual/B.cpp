#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, w, h;
    std::cin >> n >> w >> h;

    std::vector<std::pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[i] = {x - w, x + w};
    }

    for (int i = 0; i < n; i++)
    {
        int y;
        std::cin >> y;
        b[i] = {y - h, y + h};
    }

    auto between = [&](auto x, auto l, auto r)
    {
        return l <= x and x <= r;
    };

    constexpr i64 inf = 1e10;
    i64 min = -inf, max = inf;

    for (int i = 0; i < n; i++)
    {
        min = std::max<i64>({min, std::min(b[i].first - a[i].first, b[i].second - a[i].second)});
        max = std::min<i64>({max, std::max(b[i].second - a[i].second, b[i].first - a[i].first)});
    }

    if (min > max)  
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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