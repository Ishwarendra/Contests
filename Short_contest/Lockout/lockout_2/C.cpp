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
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }   

    int roots = 0, root = 0;
    for (int i = 0; i < n; i++)
    {
        if (std::ssize(adj[i]) > 2)
        {
            roots++;
            root = i;
        }
    }

    std::set<int> leaf;

    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        int leaf_ = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u);
            leaf_ = 0;
        }

        if (leaf_)
            leaf.emplace(u + 1);
    }; dfs(root, root);

    if (roots <= 1)
    {
        std::cout << "Yes\n";
        std::cout << std::ssize(leaf) << "\n";
        for (auto x : leaf)
            std::cout << root + 1 << ' ' << x << "\n";
    }
    else
        std::cout << "No\n";
    
    return 0;
}