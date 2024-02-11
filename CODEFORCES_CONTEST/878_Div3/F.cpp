#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void chkmin(int &a, int b)
{
    if (a > b)
        a = b;
}

void solve()
{
    int n, m, r;
    std::cin >> n >> m >> r;

    std::map<int, std::set<int>> sx, sy;
    for (int i = 0; i < r; i++)
    {
        int t, d, c;
        std::cin >> t >> d >> c;

        if (d == 1)
            sx[t].emplace(c);
        else
            sy[t].emplace(c);
    }

    std::vector dp(n + 1, std::vector(m + 1, std::vector(r + 1, inf)));

    auto safe = [&](int i, int j, int t)
    {
        return !sx[t].count(i) and !sy[t].count(j);
    };

    dp[0][0][0] = 0;
    for (int i = 1; i < r + 1; i++)
        chkmin(dp[0][0][i], safe(0, 0, dp[0][0][i - 1] + 1) ? dp[0][0][i - 1] + 1 : inf);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int t = 0; t <= r; t++)
            {
                if (i + 1 <= n)
                {
                    chkmin(dp[i + 1][j][t], safe(i + 1, j, dp[i][j][t] + 1) ? dp[i][j][t] + 1 : inf);
                    if (t > 0)
                        chkmin(dp[i + 1][j][t], safe(i + 1, j, dp[i + 1][j][t - 1] + 1) ? dp[i + 1][j][t - 1] + 1 : inf);
                }
                if (j + 1 <= m)
                {
                    chkmin(dp[i][j + 1][t], safe(i, j + 1, dp[i][j][t] + 1) ? dp[i][j][t] + 1 : inf);
                    if (t > 0)
                        chkmin(dp[i][j + 1][t], safe(i, j + 1, dp[i][j + 1][t - 1] + 1) ? dp[i][j + 1][t - 1] + 1 : inf);
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= r; i++)
        ans = std::min(ans, dp[n][m][i]);

    std::cout << (ans < inf ? ans : -1) << "\n";
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