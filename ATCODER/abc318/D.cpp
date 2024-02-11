#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector d(n, std::vector(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            std::cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    i64 ans = 0;

    std::vector dp(1 << n, 0LL);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (getBit(mask, u) or getBit(mask, v) or u == v)
                    continue;

                int mask2 = mask ^ (1 << u) ^ (1 << v);
                dp[mask2] = std::max(dp[mask2], dp[mask] + d[u][v]);
            }
        }

        ans = std::max(ans, dp[mask]);
    }
    
    std::cout << ans;

    return 0;
}