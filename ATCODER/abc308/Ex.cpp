#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::vector par(n, -1);
    auto bfs = [&](int src, int ignore)
    {
        std::fill(std::begin(par), std::end(par), -1);

        std::set<std::pair<i64, int>> s;
        std::vector<i64> d(n, inf);
        s.emplace(0, src);
        d[src] = 0;

        std::vector<int> label(n, -1), done(n);
        std::array<int, 3> ret { src, -1, -1 };

        i64 ans = inf;
        while (!s.empty())
        {
            auto [dist, u] = *std::begin(s);
            done[u] = 1;
            s.erase(std::begin(s));

            for (auto [v, w] : adj[u])
            {
                if (u == src and v == ignore)
                    continue;
                if (u == ignore and v == src)
                    continue;

                if (d[v] == inf or d[v] > d[u] + w)
                {
                    if (label[u] == -1)
                        label[v] = v;
                    else
                        label[v] = label[u];

                    s.erase(std::pair<i64, int>{d[v], v});
                    d[v] = d[u] + w;
                    par[v] = u;
                    s.emplace(d[v], v);
                }
                else if (done[v] and par[v] != u and par[u] != v and label[u] != label[v])
                {
                    if (ans > d[v] + d[u] + w)
                    {
                        ans = d[v] + d[u] + w;
                        ret[1] = v, ret[2] = u;
                    }
                }
            }
        }

        auto [_, to1, to2] = ret;
        if (to1 == -1 or to2 == -1 or ans == inf)
            return inf;

        std::vector<int> in_cycle(n);
        in_cycle[src] = 1;

         while (to1 != src)
        {
            in_cycle[to1] = 1;
            to1 = par[to1];
        }
 
        while (to2 != src)
        {
            in_cycle[to2] = 1;
            to2 = par[to2];
        }

        assert(to1 == to2 and to1 == src);
        return ans;
    };

    i64 ans = inf;
    for (int u = 0; u < n; u++)
    {
        std::vector<std::tuple<int, int, int>> check;
        for (auto [v, w] : adj[u])
            check.emplace_back(w, u, v);

        std::sort(std::begin(check), std::end(check));
        if (std::size(check) > 3)
            check.resize(3);

        for (auto &[w, st, en] : check)
            ans = std::min(ans, bfs(st, en) + w);
    }

    std::cout << (ans < inf ? ans : -1);
    
    return 0;
}