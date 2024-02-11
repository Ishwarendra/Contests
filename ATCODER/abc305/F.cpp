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

    std::vector vis(n, 0);
    std::vector<std::vector<int>> adj(n);

    auto query = [&](int u, bool pr = true)
    {
        if (pr)
            std::cout << u + 1 << std::endl;
        if (u + 1 == n)
        {
            std::string s;
            std::cin >> s;
            std::exit(0);
        }

        int len;
        std::cin >> len;

        adj[u].resize(len);
        for (int i = 0; i < len; i++)
        {
            std::cin >> adj[u][i];
            adj[u][i]--;
        }
    };  

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        query(u, u != 0);
        vis[u] = 1;
        
        for (int v : adj[u])
        {
            if (vis[v])
                continue;

            dfs(v, u);
        }

        query(p);
    };

    dfs(0, 0);
    
    return 0;
}