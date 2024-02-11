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
    std::vector<int> outdeg(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);

        outdeg[u]++;
        outdeg[v]++;
    }

    int root = -1;
    bool possible = false;

    for (int i = 0; i < n; i++)
    {
        if (outdeg[i] == 1 and root == -1)
            root = i;
        else if (outdeg[i] == 1)
            possible = true;
    }

    if (root == -1 || m == 0)
    {
        std::cout << "No\n";
        return 0;
    }

    std::vector<int> done(n);

    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        done[u] = 1;
        int cnt = 0;

        for (int v : adj[u])
        {
            if (done[v])
                continue;

            cnt++;
            dfs(v, u);
        }

        if (cnt > 1)
            possible = false;

    }; dfs(root, root);

    for (int i = 0; i < n; i++)
    {
        if (!done[i])
            possible = false;
    }

    std::cout << (possible ? "Yes\n" : "No\n");

    return 0;
}