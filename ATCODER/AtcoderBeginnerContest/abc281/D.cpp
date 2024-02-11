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
    
    int n, k, d;
    std::cin >> n >> k >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector dp(n, std::vector(k, std::vector(d, -1LL)));
    for (int i = 0; i < n; i++)
        dp[i][0][a[i] % d] = a[i];

    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int p = 0; p < d; p++)
            {
                if (dp[i][j][p] == -1)
                    continue;

                dp[i + 1][j][p] = std::max(dp[i + 1][j][p], dp[i][j][p]);
                if (j + 1 < k)
                    dp[i + 1][j + 1][(p + a[i + 1]) % d] = std::max(dp[i + 1][j + 1][(p + a[i + 1]) % d], dp[i][j][p] + a[i + 1]);       
            }
        }
    }

    std::cout << dp[n - 1][k - 1][0];
    
    return 0;
}