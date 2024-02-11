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

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < n - 1; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v, i + 1);
        adj[v].emplace_back(u, i + 1);
    }

    std::vector<int> tme(n);
    std::function<void(int, int, int)> dfs = [&](int u, int p, int time)
    {
        tme[u] = time;
        for (auto [v, tv] : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u, tv);
        }
    }; dfs(0, 0, 0);

    std::function<int(int, int)> dfs2;
    dfs2 = [&](int u, int p)
    {
        int ans = 0;
        for (auto [v, tv] : adj[u])
        {
            if (v == p)
                continue;
            ans = std::max(ans, dfs2(v, u) + (tv < tme[u]));
        }   

        return ans;
    };

    std::cout << dfs2(0, 0) + 1 << "\n";
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