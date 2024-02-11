#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> par(n);

    auto shortestCycle = [&](int src)
    {
        std::fill(std::begin(par), std::end(par), -1);
        std::vector<int> d(n, inf);
        d[src] = 0;

        std::queue<int> q;
        q.emplace(src);

        int ans = inf;
        std::array<int, 3> ret {src, -1, -1};
        std::vector<int> label(n, -1);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] == inf)
                {
                    if (label[u] == -1)
                        label[v] = v;
                    else
                        label[v] = label[u];

                    d[v] = d[u] + 1;
                    par[v] = u;
                    q.emplace(v);
                }
                else if (par[v] != u and par[u] != v and label[u] != label[v])
                {
                    if (ans > d[v] + d[u] + 1)
                    {
                        ans = d[v] + d[u] + 1;
                        ret[1] = v, ret[2] = u;
                    }
                }
            }
        }

        return ret;
    };

    auto check = [&](int src)
    {
        std::vector<std::pair<int, int>> ans;
        auto [_, to1, to2] = shortestCycle(src);
        if (to1 == -1)
            return ans;

        auto add = [&](int x, int y)
        {
            ans.emplace_back(std::min(x, y) + 1, std::max(x, y) + 1);
        };

        add(to1, to2);
        std::vector<int> in_cycle(n);
        in_cycle[to1] = in_cycle[to2] = 1;
        while (to1 != src)
        {
            in_cycle[par[to1]] = 1;
            add(to1, par[to1]);
            to1 = par[to1];
        }

        while (to2 != src)
        {
            in_cycle[par[to2]] = 1;
            add(to2, par[to2]);
            to2 = par[to2];
        }

        assert(to1 == to2 and to1 == src);
        int cnt = 0;
        for (auto v : adj[src])
        {
            if (!in_cycle[v])
            {
                cnt++;
                add(src, v);
                if (cnt == 2)
                    break;
            }
        }

        if (cnt != 2)
            ans.clear();

        return ans;
    };

    for (int i = 0; i < n; i++)
    {
        auto edges = check(i);
        if (edges.empty())
            continue;

        std::cout << "YES\n" << std::size(edges) << "\n";
        for (auto [u, v] : edges)
            std::cout << u << " " << v << "\n";
        return;
    }

    std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}