#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
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

    std::vector<int> cnt(n, 1);
    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }; dfs(0, 0);

    std::function<int(int, int)> get_centroid;
    get_centroid = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            if (cnt[v] * 2 > n)
                return get_centroid(v, u);
        }
        
        return u;
    }; 

    int root = get_centroid(0, 0);
    std::vector<int> tree, ans(n);
    dfs = [&](int u, int p)
    {
        tree.emplace_back(u);
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
        }
    }; dfs(root, root);

    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            ans[i] = tree[i / 2];
        else
            ans[i] = tree[n / 2 + i / 2];
    }

    std::cout << root + 1 << "\n";
    for (int i = 0; i < n; i++)    
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
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