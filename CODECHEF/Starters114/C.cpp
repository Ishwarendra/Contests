#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
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

    std::vector<int> d(n, -1), leaf(n), cnt(n);

    auto dfs = [&](auto && self, int u, int p) -> void
    {
        d[u] = d[p] + 1;
        int l = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            cnt[u] += cnt[v];
            l = 0;
        }

        leaf[u] = l;
        if (l)
            cnt[u] = l;
    }; dfs(dfs, 0, 0);

    std::vector<int> dl(n, -1);
    std::queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (leaf[i])
        {
            dl[i] = 0;
            q.emplace(i);
        }
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dl[v] != -1)
                continue;

            dl[v] = dl[u] + 1;
            q.emplace(v);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (leaf[i])
            continue;
        if (d[i] >= dl[i])
            ans = std::max(ans, cnt[i]);
    }

    std::cout << ans << "\n";
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