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

    std::vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        std::sort(std::begin(adj[i]), std::end(adj[i]));
        std::cout << std::size(adj[i]) << " ";
        for (auto v : adj[i])
            std::cout << v << " ";
        std::cout << "\n";
    }
    
    return 0;
}