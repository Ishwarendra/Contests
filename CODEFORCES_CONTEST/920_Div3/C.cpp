#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 2e9;

void chmin(i64 &a, i64 b)
{
    if (a > b)
        a = b;
}

void solve()
{
    int n, f, a, b;
    std::cin >> n >> f >> a >> b;

    std::vector<int> m(n);
    for (int i = 0; i < n; i++)
        std::cin >> m[i];

    std::vector dp(n + 1, std::array { inf, inf });
    dp[0][0] = dp[0][1] = 0;

    int p = 0;
    for (int i = 0; i < n; i++)
    {
        chmin(dp[i + 1][1], dp[i][0] + b);
        chmin(dp[i + 1][1], dp[i][1] + 1LL * (m[i] - p) * a);
        chmin(dp[i + 1][0], dp[i][0] + b);
        chmin(dp[i + 1][0], dp[i][1] + 1LL * (m[i] - p) * a);
        p = m[i];
    }

    i64 min = std::min(dp.back()[0], dp.back()[1]);
    std::cout << (min < f ? "YES\n" : "NO\n");
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