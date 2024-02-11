#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> t(m), c(m);
    for (int i = 0; i < m; i++)
        std::cin >> t[i];
    for (int i = 0; i < m; i++)
        std::cin >> c[i];

    constexpr int inf = 1e9 + 1e5;
    std::vector dp(n + 1, std::vector(5, -inf));
    dp[0][0 + 2] = 0;

    for (int i = 1, pos = 0; i <= n; i++)
    {
        // gap = a - b
        for (int gap = 0; gap < 5; gap++)
        {
            if (gap - 1 >= 0)
                dp[i][gap] = std::max(dp[i][gap], dp[i - 1][gap - 1]);
            if (gap + 1 < 5)
                dp[i][gap] = std::max(dp[i][gap], dp[i - 1][gap + 1]);
        }

        if (pos < m and i == t[pos])
        {
            if (c[pos] == 1)
            {
                for (int gap = 1; gap <= 2; gap++)
                    dp[i][gap + 2]++;

                dp[i][0 + 2] = std::max({dp[i][0 + 2], dp[i][-1 + 2], dp[i][-2 + 2]});
                dp[i][-1 + 2] = dp[i][-2 + 2] = -inf;
            }   
            else
            {
                for (int gap = -2; gap <= -1; gap++)
                    dp[i][gap + 2]++;

                dp[i][0 + 2] = std::max({dp[i][0 + 2], dp[i][1 + 2], dp[i][2 + 2]});
                dp[i][1 + 2] = dp[i][2 + 2] = -inf;
            }

            pos++;
        }
    }

    // for (auto p : dp)
    //     print(p)

    std::cout << *std::max_element(std::begin(dp[n]), std::end(dp[n])) << "\n";
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