#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    std::array<int, 2> k{}, q{};
    std::cin >> k[0] >> k[1] >> q[0] >> q[1];

    int ans = 0;
    std::set<std::array<int, 2>> hs;
    for (auto dx : {-a, a, -b, b})
    {
        for (auto dy : {-b, b, -a, a})
        {
            if (std::abs(dx) == std::abs(dy) and a != b)
                continue;
            hs.insert({k[0] + dx, k[1] + dy});
        }
    }

    for (auto &[x, y] : hs)
    {
        if (std::abs(q[0] - x) == a)
            ans += std::abs(q[1] - y) == b;
        else if (std::abs(q[0] - x) == b)
            ans += std::abs(q[1] - y) == a;
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