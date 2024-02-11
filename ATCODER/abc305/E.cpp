#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> p(k), h(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> p[i] >> h[i];
        p[i]--;
    }

    constexpr int inf = 1e9;

    std::set<std::pair<int, int>, std::greater<>> s;
    std::vector<int> d(n, -inf);
    for (int i = 0; i < k; i++)
    {
        d[p[i]] = h[i];
        s.emplace(d[p[i]], p[i]);
    }

    while (!s.empty())
    {
        auto [dist, u] = *std::begin(s);
        s.erase(std::begin(s));

        if (dist == 0)
            continue;

        for (int v : adj[u])
        {
            if (d[v] < dist - 1)
            {
                s.erase({d[v], v});
                d[v] = dist - 1;
                s.emplace(d[v], v);
            }
        }
    }

    std::vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (d[i] != -inf)
            ans.emplace_back(i);
    }

    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::size(ans); i++)
        std::cout << ans[i] + 1 << " \n"[i + 1 == std::size(ans)];
    
    return 0;
}