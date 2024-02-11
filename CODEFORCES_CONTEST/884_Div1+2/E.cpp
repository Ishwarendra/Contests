#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<int, int>> adj[n + m];

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        int diff = 0;
        for (int j = 0; j < 2; j++)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
            if (x2 - x1 == 1 and y2 - y1 == 1)
                diff = 1;
        }

        int u = std::min(x1, x2);
        int v = n + std::min(y1, y2);

        adj[u].emplace_back(v, diff);
        adj[v].emplace_back(u, diff);
    }

    std::vector<int> vis(n + m, -1);
    int possible = 1;
    std::function<void(int, int)> dfs = [&](int u, int col)
    {
        vis[u] = col;
        for (auto [v, w] : adj[u])
        {
            if (vis[v] == -1)
                dfs(v, col ^ w);
            else if (vis[v] != (col ^ w))
                possible = 0;
        }
    }; 

    for (int i = 0; i < n + m; i++)
    {
        if (vis[i] == -1)
            dfs(i, 0);
    }

    std::cout << (possible ? "YES\n" : "NO\n");
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