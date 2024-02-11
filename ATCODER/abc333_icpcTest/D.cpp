#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector sz(n, 1);
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v != p)
            {
                self(self, v, u);
                sz[u] += sz[v];
            }
        }
    }; dfs(dfs, 0, 0);

    int sum = 0, ans = 1;
    for (int v : adj[0])
    {
        sum += sz[v];
        ans = std::max(ans, sz[v]);
    }

    ans = sum - ans + 1;

    std::cout << ans;
}