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

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::string s;
    std::cin >> s;

    const int m = std::__lg(n) + 2;
    std::vector dep(n, -1);
    std::vector dp(n, std::vector(m, 0));

    auto dfs = [&](auto && self, int u, int p) -> void
    {
        dp[u][0] = p;
        dep[u] = dep[p] + 1;
        for (int v : adj[u])
        {
            if (v != p)
                self(self, v, u);
        }
    }; dfs(dfs, 0, 0);

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
        for (int pos = m - 1; pos >= 0; pos--)
        {
            if ((diff >> pos) & 1)
                u = dp[u][pos];
        }

        if (u == v)
            return u;

        for (int pos = m - 1; pos >= 0; pos--)
        {
            if (dp[u][pos] != dp[v][pos])
                u = dp[u][pos], v = dp[v][pos];
        }

        return dp[u][0];
    };

    while (q--)
    {
        int t, u, v;
        std::cin >> t >> u >> v;
        u--, v--;

        std::vector<int> up, down;
        int l = lca(u, v);

        while (u != l)
        {
            up.emplace_back(u);
            u = dp[u][0];
        }

        up.emplace_back(l);

        while (v != l)
        {
            down.emplace_back(v);
            v = dp[v][0];
        }

        std::reverse(std::begin(down), std::end(down));
        up.insert(std::end(up), std::begin(down), std::end(down));

        if (t == 2)
        {
            for (auto id : up)
                s[id] ^= '(' ^ ')';
            print(s);
        }
        else
        {
            int pmin = 0, sum = 0;
            for (auto id : up)
            {
                if (s[id] == '(')
                    sum++;
                else
                    sum--;
                pmin = std::min(pmin, sum);
            }

            if (sum == 0 and pmin >= 0)
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();

    return 0;
}