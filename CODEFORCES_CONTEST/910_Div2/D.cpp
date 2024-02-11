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

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)
        std::cin >> a[i][0];
    for (int i = 0; i < n; i++)
        std::cin >> a[i][1];

    std::sort(std::begin(a), std::end(a), [&](auto & x, auto & y)
    {
        return x[1] < y[1];
    });

    i64 base = 0;
    for (auto &[x, y] : a)
        base += std::abs(x - y);

    auto ans = base;
    std::multiset<int, std::greater<>> maxa, maxb;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] <= a[i][1])
            maxa.emplace(a[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][0] <= a[i][1])
        {
            if (maxa.empty())
                continue;
            int x = *std::begin(maxa);
            ans = std::max(ans, base + 2 * (x - a[i][1]));
        }
        else
        {
            if (!maxa.empty())
            {
                int x = *std::begin(maxa);
                ans = std::max(ans, base + 2 * (x - a[i][0]));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][1] <= a[i][0])
            maxb.emplace(a[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][0] >= a[i][1])
        {
            if (maxb.empty())
                continue;
            int x = *std::begin(maxb);
            ans = std::max(ans, base + 2 * (x - a[i][0]));
        }
        else
        {
            if (maxb.empty())
                continue;
            int x = *std::begin(maxb);
            ans = std::max(ans, base + 2 * (x - a[i][1]));
        }
    }

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