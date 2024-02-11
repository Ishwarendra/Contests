#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;

constexpr i128 LIMIT = 1e18;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<int, i128>> a;
    std::vector<i128> length;
    i128 len = 0;
    for (int i = 0; i < n; i++)
    {
        int t, x;
        std::cin >> t >> x;

        if (len >= LIMIT)
            continue;

        if (t == 1)
        {
            len++;
            a.emplace_back(x, 1);
            length.emplace_back(len);
        }
        else
        {
            len += len * x;
            a.emplace_back(x, 2);
            length.emplace_back(len);
        }
    }

    std::map<i64, int> dp;
    n = std::size(length);
    while (q--)
    {
        i64 k;
        std::cin >> k;
        k--;

        auto f = [&](auto &&self, i64 x) -> int
        {
            if (dp.contains(x))
                return dp[x];

            auto id = std::upper_bound(std::begin(length), std::end(length), x) - std::begin(length);
            if (a[id].second == 1)
            {
                assert(x == length[id] - 1);
                return a[id].first;
            }

            return dp[x] = self(self, x % length[id - 1]);
        };

        std::cout << f(f, k) << " \n"[q == 0];
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