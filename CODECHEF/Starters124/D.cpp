#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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

    std::vector<std::pair<int, int>> qry(q);
    std::vector<int> dep(n, -1);
    auto dfs1 = [&](auto &&self, int u, int p) -> void
    {
        dep[u] = dep[p] + 1;
        for (int v : adj[u])
        {
            if (v != p)
                self(self, v, u);
        }
    }; dfs1(dfs1, 0, 0);

    int min = q, max = -1;
    int i_ = 0;
    for (auto &[t, u] : qry)
    {
        std::cin >> t >> u;

        if (t == 1)
            min = std::min(min, i_);
        else
            max = std::max(max, i_);

        i_++;
    }

    if (min < max)
    {
        auto bfs = [&](int src)
        {
            std::vector<int> d(n, -1);
            std::queue<int> q;
            q.emplace(src);
            d[src] = 0;

            while (!q.empty())
            {
                auto u = q.front();
                q.pop();

                for (int v : adj[u])
                {
                    if (d[v] == -1)
                    {
                        q.emplace(v);
                        d[v] = d[u] + 1;
                    }
                }
            }

            return d;
        };

        auto d = bfs(0);
        std::map<int, int> distance;
        std::set<int> nodes;
        int cnt = 0;

        for (auto &[t, u] : qry)
        {
            u--;
            if (t == 1)
                std::cout << cnt << "\n";
            else
            {
                if (u == 0)
                    continue;

                if (nodes.count(u))
                {
                    nodes.erase(u);

                    cnt -= distance[d[u]] == 1;
                    distance[d[u]]--;
                    cnt += distance[d[u]] == 1;
                    if (distance[d[u]] == 0)
                        distance.erase(d[u]);

                }
                else
                {
                    nodes.emplace(u);
                    cnt -= distance[d[u]] == 1;
                    distance[d[u]]++;
                    cnt += distance[d[u]] == 1;
                }
            }
        }

        return;
    }

    std::vector<int> present(n);
    for (auto &[t, u] : qry)
    {
        if (t == 1)
            break;
        u--;
        present[u] ^= 1;
    }

    std::vector<int> dp(n);
    std::vector<std::map<int, int>> cnt(n);
    std::vector<std::set<int>> del(n);

    auto dfs2 = [&](auto &&self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            self(self, v, u);

            if (std::size(cnt[u]) < std::size(cnt[v]))
            {
                std::swap(cnt[u], cnt[v]);
                std::swap(del[u], del[v]);
            }

            for (auto &[d, f] : cnt[v])
            {
                cnt[u][d] += f;
                if (cnt[u][d] > 1)
                    del[u].emplace(d);
            }
        }

        dp[u] = int(std::size(cnt[u])) - int(std::size(del[u]));
        if (present[u])
            cnt[u][dep[u]] = 1;
    }; dfs2(dfs2, 0, 0);

    // print(dp)
    for (auto &[t, u] : qry)
    {
        if (t == 2)
            continue;
        u--;
        std::cout << dp[u] << "\n";
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