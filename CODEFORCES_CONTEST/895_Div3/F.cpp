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

    std::vector<int> c(n), indeg(n);
    std::set<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        a--;
        adj[i].emplace(a);
        indeg[a]++;
    }

    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    std::vector<int> ans, vis(n);
    std::set<int> del;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            del.emplace(i);
    }

    while (!del.empty())
    {
        auto u = *std::begin(del);
        del.erase(u);

        vis[u] = 1;
        ans.emplace_back(u);
        for (int v : adj[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                del.emplace(v);
        }
    }

    std::vector<std::pair<int, int>> cyc;
    std::function<void(int)> dfs = [&](int u) -> void
    {
        vis[u] = 1;
        cyc.emplace_back(c[u], u);
        for (auto v : adj[u])
        {
            if (!vis[v])
                dfs(v);
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;

        cyc.clear();
        dfs(i);
        
        int st = 0;
        for (int u = 0; u < std::size(cyc); u++)
        {
            if (cyc[u].first < cyc[st].first)
                st = u;
        }

        st = (st + 1) % std::size(cyc);
        for (int cnt = 0; cnt < std::size(cyc); cnt++, st = (st + 1) % std::size(cyc))
            ans.emplace_back(cyc[st].second);
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
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