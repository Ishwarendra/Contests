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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    std::set<std::pair<int, int>> edge;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        edge.emplace(u, v);
    }

    constexpr int inf = 1e9;
    auto bfs = [&](int src)
    {
        std::vector<int> d(n, inf);
        std::queue<int> q;
        q.emplace(src);
        d[src] = 0;

        int ans = 0;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (auto v : adj[cur])
            {
                if (d[v] == inf)
                {
                    d[v] = d[cur] + 1;
                    q.emplace(v);
                }
            }
        }

        // print(d)
        for (int i = 0; i < n; i++)
        {
            if (i == src)
                continue;

            if (d[i] >= 2 and d[i] != inf)
            {
                ans += !edge.count({src, i});
            }
        }

        return ans;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans += bfs(i);

    std::cout << ans;

    return 0;
}