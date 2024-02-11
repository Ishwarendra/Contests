#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    x--, y--;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 0; i < n; i++)
        std::sort(std::begin(adj[i]), std::end(adj[i]));

    std::queue<std::pair<int, int>> q;
    std::vector<int> d(n, inf);
    d[x] = 0;
    for (int i = 0; i < std::size(adj[x]); i++)
        q.emplace(x, i);

    while (!q.empty())
    {
        auto [u, deg] = q.front();
        q.pop();

        
    }

    std::cout << (d[y] == inf ? -1 : d[y]) << "\n";
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