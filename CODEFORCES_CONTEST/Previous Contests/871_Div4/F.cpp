#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> deg(n), adj[n];
    for (int i = 0; i < m; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[deg[i]]++;

    auto check = [&](int u)
    {
        int x = deg[u];
        int y = -1;

        for (int v : adj[u])
        {
            if (y == -1)
                y = deg[v];
            else if (y != deg[v])
                return false;
        }

        int child = adj[u][0];
        for (int v : adj[child])
        {
            if (v == u)
                continue;
            if (deg[v] != 1)
                return false;
        }

        std::cout << x << " " << y - 1 << "\n";
        return true;
    };

    for (int i = 0; i < n; i++)
    {
        if (check(i))
            return;
    }
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