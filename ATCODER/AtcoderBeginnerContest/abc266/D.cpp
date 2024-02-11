#include <bits/stdc++.h>

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

    std::vector<int> t(n), x(n), a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> t[i] >> x[i] >> a[i];

    constexpr int inf = 1e9;
    std::vector<i64> dp(n, -inf);

    if (t[0] >= x[0])
        dp[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        if (t[i] >= x[i])
            dp[i] = a[i];

        for (int j = 1; j <= 100 and i - j >= 0; ++j)
        {
            int need = std::abs(x[i] - x[i - j]);
            int can = t[i] - t[i - j];

            if (need > can)
                continue;
            dp[i] = std::max(dp[i], dp[i - j] + a[i]);
        }
    }

    // for (int i = 0; i < n; ++i)
    //     print(dp[i][x[i]])

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans = std::max<i64>(ans, dp[i]);

    std::cout << ans << "\n";

    return 0;
}