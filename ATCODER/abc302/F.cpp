#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + m);
    std::vector<int> d(n + m, inf);
    std::vector<int> srcs, sinks;

    for (int i = 0; i < n; i++)
    {
        int len;
        std::cin >> len;

        int src = 0, sink = 0;
        for (int j = 0; j < len; j++)
        {
            int x;
            std::cin >> x;
            x--;

            src |= x == 0;
            sink |= x == m - 1;

            adj[i].emplace_back(x + n);
            adj[x + n].emplace_back(i);
        }

        if (src)
            srcs.emplace_back(i);
        if (sink)
            sinks.emplace_back(i);
    }

    int ans = inf;
    std::queue<int> q;
    for (auto src : srcs)
    {
        d[src] = 0;
        q.emplace(src);
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int v : adj[u]) 
        {
            if (d[v] == inf)
            {
                d[v] = d[u] + 1;
                q.emplace(v);
            }
        }
    }

    for (auto sink : sinks)
        ans = std::min(ans, d[sink]);

    std::cout << (ans < inf ? ans / 2 : -1);
    
    return 0;
}