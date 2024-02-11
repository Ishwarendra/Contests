#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1 << 30;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    auto check = [&](std::unordered_set<int> &a)
    {
        std::unordered_set<int> vis;
        int siz = 0, max = 0;
        std::function<void(int)> dfs = [&](int u)
        {
            siz++;
            vis.emplace(u);
            for (int v : adj[u])
            {
                if (!a.count(v) or vis.count(v))
                    continue;
                dfs(v);
            }
        };

        for (auto u : a)
        {
            if (!vis.count(u))
            {
                siz = 0;
                dfs(u);
                max = std::max(max, siz);
            }
        }

        return max >= k;
    };

    std::function<int(std::unordered_set<int> &, int)> f;
    f = [&](std::unordered_set<int> &a, int bit) -> int
    {
        if (std::size(a) < k or !check(a))
            return inf;
        if (bit < 0)
            return 0;

        std::unordered_set<int> set, unset;
        for (auto it = std::begin(a); it != std::end(a); it++)
        {
            if (getBit(b[*it], bit))
                set.emplace(*it);
            else
                unset.emplace(*it);
        }

        int res = std::min(f(set, bit - 1), f(unset, bit - 1));
        
        if (res == inf)
            res = (1 << bit) + f(a, bit - 1);

        return res;
    };

    std::unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.emplace(i);

    int cost = f(s, 29);
    if (cost == inf)
        cost = -1;
    std::cout << cost << "\n";
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