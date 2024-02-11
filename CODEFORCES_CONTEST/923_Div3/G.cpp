#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto chmin = [&](int &x, int y)
    {
        if (x > y)
            x = y;
    };

    std::vector dp(n + 1, std::vector(n + 1, inf));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        std::vector ndp(n + 1, std::vector(n + 1, inf));
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (dp[j][k] == inf)
                    continue;
                // everything painted before j, rightmost painted cell is k
                // ignore
                chmin(ndp[j][k], dp[j][k]);

                // paint right
                int k1 = std::min(n, i + a[i]);
                int j1 = (i <= j ? k1 : j);
                chmin(ndp[j1][k1], dp[j][k] + 1);

                // paint left to cover up
                if (i - a[i] + 1 <= j)
                {
                    int id = std::max(k, i + 1);
                    chmin(ndp[id][id], dp[j][k] + 1);
                }
            }
        }

        std::swap(ndp, dp);
    }

    std::cout << dp[n][n] << "\n";
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