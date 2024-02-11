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

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int k;
    std::cin >> k;

    std::set<int> q;
    std::queue<int> que;
    auto ans = std::string(n, '0');

    for (int i = 0; i < n; i++)
        q.emplace(i);

    std::vector<int> d(n, inf);
    std::map<int, int> minD;

    for (int i = 0; i < k; i++)
    {
        int p, dist;
        std::cin >> p >> dist;
        p--;

        minD[p] = dist;

        if (dist > 0)
            q.erase(p);
        else
            que.emplace(p), q.erase(p), ans[p] = '1', d[p] = 0;
    }

    while (!que.empty())
    {
        auto u = que.front();
        que.pop();

        for (auto v : adj[u])
        {
            if (d[v] == inf)
            {
                d[v] = d[u] + 1;
                que.emplace(v);
            }
        }
    }

    auto paintBlack = [&](int src)
    {
        std::vector<int> dist(n, inf);
        dist[src] = 0;

        std::queue<int> que;
        que.emplace(src);

        while (!que.empty())
        {
            auto u = que.front();
            que.pop();
            for (int v : adj[u])
            {
                if (dist[v] == inf)
                {
                    dist[v] = dist[u] + 1;
                    que.emplace(v);
                }
            }
        }

        for (auto [node, d] : minD)  
        {
            if (dist[node] < d)
                return false;
        }

        for (int i = 0; i < n; i++)
            d[i] = std::min(d[i], dist[i]);

        return true;
    };

    for (auto u : q)
    {
        if (paintBlack(u))
            ans[u] = '1';
    }

    for (int i = 0; i < n; i++)
    {
        if (minD.count(i) and d[i] != minD[i])
        {
            std::cout << "No";
            return 0;
        }
    }
        
    std::cout << "Yes\n" << ans;

    return 0;
}