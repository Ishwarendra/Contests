#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using ld = long double;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, p;
    std::cin >> n >> p;

    std::vector a(n, std::array<ld, 3>());
    std::vector<ld> have;
    i64 sum = 0;

    for (auto &[x, y, id] : a)
    {
        std::cin >> x >> y;
        sum += x;
        id = std::size(have);
        have.emplace_back(y / x);
    }

    if (p >= sum)
    {
        std::cout << -1;
        return 0;
    }

    std::sort(std::begin(a), std::end(a), [&](const auto &x, const auto &y)
    {
        return have[x[2]] < have[y[2]];
    });

    ld left = 0, right = 1e19;
    ld ans = 0;

    auto good = [&](ld mid)
    {
        ld need = 0;
        for (auto &[x, y, id] : a)
        {
            if (y - x * mid >= 0)
                continue;

            need += x * mid - y;
        }

        return need <= p * mid;
    };

    for (int i = 0; i < 500; i++)
    {
        ld mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid;
        else
            right = mid;
    }

    std::cout << std::fixed << std::setprecision(12);
    if (ans > 1e18)
        std::cout << -1;
    else
        std::cout << ans;

    return 0;
}