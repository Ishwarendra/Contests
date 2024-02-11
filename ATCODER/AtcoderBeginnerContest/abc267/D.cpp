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

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector dp(n, std::vector<i64>(m));

    constexpr i64 inf = 1e18;

    dp[0][0] = a[0];
    for (int i = 1; i < m; i++)
        dp[0][i] = -inf;

    for (int i = 1; i < n; i++)
        dp[i][0] = std::max(dp[i - 1][0], 1LL * a[i]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (j > i)
            {
                dp[i][j] = -inf;
                continue;
            }

            dp[i][j] = std::max(dp[i - 1][j - 1] + 1LL * (j + 1) * a[i], dp[i - 1][j]);
        }
    }

    std::cout << dp[n - 1][m - 1];

    return 0;
}