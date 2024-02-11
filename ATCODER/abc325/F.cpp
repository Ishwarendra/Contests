#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::array<int, 2> l{}, c{}, k{};

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < 2; i++)
        std::cin >> l[i] >> c[i] >> k[i];

    std::vector<i64> dp(k[0] + 1, 0);
    auto chmin = [&](auto &x, auto y)
    {
        if (x > y)
            x = y;
    };

    for (int i = 0; i < n; i++)
    {
        std::vector<i64> ndp(k[0] + 1, inf);
        for (int kp = 0; kp <= k[0]; kp++)
        {
            for (int k0 = kp; k0 <= k[0]; k0++)
            {
                int need = a[i] - (k0 - kp) * l[0];
                int k1 = 0;
                if (need > 0)
                    k1 = (need + l[1] - 1) / l[1];

                chmin(ndp[k0], dp[kp] + k1);
            }
        }

        std::swap(ndp, dp);
    }

    i64 ans = inf;
    for (int k0 = 0; k0 <= k[0]; k0++)
    {
        if (dp[k0] > k[1])
            continue;

        ans = std::min(ans, 1LL * k0 * c[0] + dp[k0] * c[1]);
    }

    std::cout << (ans == inf ? -1 : ans);
    
    return 0;
}