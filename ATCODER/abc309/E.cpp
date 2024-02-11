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
    for (int i = 1; i < n; i++)
    {
        int p;
        std::cin >> p;
        p--;
        adj[p].emplace_back(i);
    }

    std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> s;
    std::vector<int> d(n, -1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        s.erase({d[x - 1], x - 1});
        d[x - 1] = std::max(d[x - 1], y);
        s.emplace(d[x - 1], x - 1);
    }

    while (!s.empty())
    {
        auto [have, u] = *std::begin(s);
        s.erase(std::begin(s));

        if (have == 0)
            continue;

        for (int v : adj[u])
        {
            if (d[v] != -1 and adj[v].empty())
                continue;

            if (d[v] < have - 1)
            {
                s.erase({d[v], v});
                d[v] = have - 1;
                s.emplace(d[v], v);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += d[i] >= 0;

    std::cout << ans;

    return 0;
}