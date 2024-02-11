#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e10;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>{});
    for (auto &[x, y] : a)
        std::cin >> x >> y;

    std::sort(std::begin(a), std::end(a));
    std::multiset<i64> b, c;
    for (int i = 1; i < n; i++)
        c.emplace(a[i][1]);

    i64 ans = std::abs(*(--std::end(c)) - a[0][0]);
    for (int i = 1; i < n; i++)
    {
        b.emplace(a[i - 1][1]);
        c.erase(c.find(a[i][1]));

        auto it = b.lower_bound(a[i][0]);
        std::array<i64, 3> num{inf, inf, inf}; 
        if (it != std::end(b))
            num[0] = *it;
        if (it != std::begin(b))
            num[1] = *std::prev(it);

        if (!c.empty())
        {
            num[2] = *(--std::end(c));
            std::array<i64, 3> diff{};
            for (int j = 0; j < 3; j++)
                diff[j] = std::abs(num[j] - a[i][0]);

            ans = std::min(ans, diff[2]);
            if (num[0] > num[2])
                ans = std::min(ans, diff[0]);
            if (num[1] > num[2])
                ans = std::min(ans, diff[1]);
        }
        else
        {
            for (int j = 0; j < 3; j++)
                num[j] = std::abs(num[j] - a[i][0]);
            ans = std::min(ans, std::min(num[1], num[0]));
        }
    }

    std::cout << ans << "\n";
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