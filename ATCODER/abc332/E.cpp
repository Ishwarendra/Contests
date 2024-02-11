#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 2e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d;
    std::cin >> n >> d;

    const int all = (1 << n) - 1;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> sum(1 << n, 0);
    for (int i = 0; i < n; i++)
        sum[(1 << i)] = a[i];

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    auto chmin = [&](auto &x, auto y)
    {
        if (x > y)
            x = y;
    };

    for (int i = 0; i < n; i++)
    {
        std::vector<int> nsum(1 << n, 0);
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (getBit(mask, i))
                nsum[mask] = sum[mask] + sum[mask ^ (1 << i)];
            else
                nsum[mask] = sum[mask];
        }

        sum = std::move(nsum);
    }

    std::vector<i64> dp(1 << n, inf);
    dp[0] = 0;
    for (int i = 0; i < d; i++)
    {
        std::vector<i64> ndp(1 << n, inf);
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int mask2 = all ^ mask;
            for (int cand = mask2; ; cand = (cand - 1) & mask2)
            {
                int s = sum[cand];
                chmin(ndp[mask | cand], dp[mask] + 1LL * s * s);
                if (!cand)
                    break;
            }
        }

        dp = std::move(ndp);
    }

    i64 sqsum = dp.back();
    std::cout << std::fixed << std::setprecision(12);
    std::cout << 1.0L * (sqsum * d - 1LL * sum[all] * sum[all]) / d / d;
    
    return 0;
}