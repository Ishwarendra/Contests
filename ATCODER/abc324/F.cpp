#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr double inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, b, c;
        std::cin >> u >> v >> b >> c;
        u--, v--;
        adj[u].push_back({v, b, c});
    }

    double left = 0, right = 2e5;
    auto good = [&](double mid)
    {
        std::vector<double> dp(n, -inf);
        dp[0] = 0;
        for (int u = 0; u < n; u++)
        {
            for (auto [v, b, c] : adj[u])
                dp[v] = std::max(dp[v], dp[u] + b - c * mid);
        }

        return dp[n - 1] > 0.;
    };

    for (int i = 0; i < 100; i++)
    {
        double mid = std::midpoint(left, right);
        if (good(mid))
            left = mid;
        else
            right = mid;
    }

    std::cout << std::fixed << std::setprecision(12) << left;

    return 0;
}