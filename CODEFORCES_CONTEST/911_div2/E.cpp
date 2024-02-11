#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<std::vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        radj[v].emplace_back(u);
    }

    int time = -1;
    std::vector<int> tout(n), ord(n);
    auto dfs = [&](auto self, int u) -> void
    {
        time++;
        ord[u] = 1;
        for (int v : adj[u])
        {
            if (!ord[v])
                self(self, v);
        }
        tout[u] = time++;
    }; 

    for (int i = 0; i < n; i++)
    {
        if (!ord[i])
            dfs(dfs, i);
    }

    std::iota(std::begin(ord), std::end(ord), 0);
    std::sort(std::begin(ord), std::end(ord), [&](int u, int v)
    {
        return tout[u] > tout[v];
    });

    std::vector<int> scc_num(n, -1);
    std::map<int, std::array<i64, 2>> cnt;
    time = 0;
    auto revDfs = [&](auto self, int u, int num) -> void
    {
        scc_num[u] = num;
        cnt[num][0]++;
        cnt[num][1] += a[u];

        for (int v : radj[u])
        {
            if (scc_num[v] == -1)
                self(self, v, num);
        }
    };

    time = 0;
    for (int u : ord)
    {
        if (scc_num[u] == -1)
            revDfs(revDfs, u, time++);
    }

    std::vector<std::vector<int>> g(time);
    for (int u = 0; u < n; u++)
    {
        for (int v : adj[u])
        {
            if (scc_num[u] != scc_num[v])
                g[scc_num[u]].emplace_back(scc_num[v]);
        }
    }

    std::fill(std::begin(ord), std::end(ord), 0);
    std::vector<std::pair<i64, i64>> dp(time);
    auto f = [&](auto self, int u) -> std::pair<i64, i64>
    {
        if (dp[u].first != 0)
            return dp[u];

        dp[u] = {cnt[u][0], -cnt[u][1]};
        for (int v : g[u])
        {
            if (ord[v])
                continue;

            self(self, v);
            std::pair<i64, i64> cand = {dp[v].first + cnt[u][0], dp[v].second - cnt[u][1]};
            dp[u] = std::max(dp[u], cand);
        }

        return dp[u];
    }; 

    for (int i = 0; i < time; i++)
    {
        if (!ord[i])
            f(f, i);
    }

    std::pair<i64, i64> ans{};
    for (int i = 0; i < time; i++)
        ans = std::max(ans, dp[i]);

    std::cout << ans.first << " " << -ans.second << "\n";
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