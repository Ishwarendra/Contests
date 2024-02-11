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
    
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, p;
        std::cin >> x >> y >> p;
        p--;

        adj[i].emplace_back(i + 1, x);
        adj[i].emplace_back(p, y);
    }

    std::set<std::pair<i64, int>> s;
    s.emplace(0, 0);

    constexpr i64 inf = 1e18;
    std::vector<i64> dist(n, inf);
    dist[0] = 0;

    while (!s.empty())
    {
        auto [d, u] = *std::begin(s);
        s.erase(std::begin(s));

        for (auto &[v, w] : adj[u])
        {
            if (d + w < dist[v])
            {
                s.erase({dist[v], v});
                dist[v] = d + w;
                s.emplace(dist[v], v);
            }
        }
    }

    std::cout << dist[n - 1];
    
    return 0;
}