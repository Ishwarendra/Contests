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

    std::vector<int> cnt(n), leaf(n, 1);
    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v != p)
            {
                leaf[u] = 0;
                dfs(v, u);
                cnt[u] += cnt[v];
            }
        }

        cnt[u] += leaf[u];
    }; dfs(0, 0);
    
    int q;
    std::cin >> q;
    
    while (q--)
    {
        int x, y;
        std::cin >> x >> y;

        x--, y--;
        std::cout << 1LL * cnt[x] * cnt[y] << "\n";
    }
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