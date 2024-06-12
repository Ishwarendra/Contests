#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        i64 x;
        std::cin >> x;

        a.emplace_back();
        while (x % 2 == 0)
            x /= 2, a.back().first++;
        while (x % 5 == 0)
            x /= 5, a.back().second++;
    }

    const int M = 60 * n;
    std::vector dp(k + 1, std::vector(M + 1, -inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        std::vector ndp(k + 1, std::vector(M + 1, -inf));
        auto [c2, c5] = a[i];
        for (int j = 0; j <= k; j++)
        {
            for (int c = 0; c <= M; c++)
            {
                if (dp[j][c] == -inf)
                    continue;

                ndp[j][c] = std::max(ndp[j][c], dp[j][c]);

                if (j == k)
                    continue;
                if (c + c5 > M)
                    continue;

                ndp[j + 1][c + c5] = std::max(ndp[j + 1][c + c5], dp[j][c] + c2);
            }
        }

        std::swap(ndp, dp);
    }

    int ans = 0;
    for (int c = 0; c <= M; c++)
        ans = std::max(ans, std::min(c, dp[k][c]));

    std::cout << ans;
    
    return 0;
}