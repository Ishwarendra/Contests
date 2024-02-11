#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    const int m = std::__lg(n) + 2;
    std::vector dp(n, std::vector(m, 0));
    std::vector dep(n, -1);

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        dp[u][0] = p;
        dep[u] = dep[p] + 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
        }
    }; dfs(0, 0);

    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }

    auto lca = [&](int u, int v)
    {
        if (dep[u] < dep[v])
            std::swap(u, v);

        int diff = dep[u] - dep[v];
        for (int i = m - 1; i >= 0; i--)
        {
            if (diff >> i & 1)
                u = dp[u][i];
        }

        if (v == u)
            return u;

        for (int i = m - 1; i >= 0; i--)
        {
            if (dp[u][i] != dp[v][i])
                u = dp[u][i], v = dp[v][i];
        }

        return dp[u][0];
    };

    auto dist = [&](int u, int v)
    {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    };

    while (q--)
    {
        int len;
        std::cin >> len;

        std::vector<int> a(len);
        for (int i = 0; i < len; i++)
        {
            std::cin >> a[i];
            a[i]--;
        }

        std::vector<int> d1(len), d2(len);
        for (int i = 0; i < len; i++)
            d1[i] = dist(a[0], a[i]);

        int max = std::max_element(std::begin(d1), std::end(d1)) - std::begin(d1);
        for (int i = 0; i < len; i++)
            d2[i] = dist(a[max], a[i]);

        max = *std::max_element(std::begin(d2), std::end(d2));
        std::cout << (max + 1) / 2 << "\n";
    }
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