#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int q;
    std::cin >> q;

    std::vector<std::array<i64, 3>> qry;
    std::vector<std::vector<int>> adj(1);
    int n = 1;

    std::vector<i64> ans(q + 1);
    auto dfs = [&](auto &&self, int u, int add) -> void
    {
        ans[u] += add;
        for (int v : adj[u])
            self(self, v, add);
    }; 

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int u;
            std::cin >> u;
            u--;

            adj.emplace_back();
            adj[u].emplace_back(n++);
        }
        else
        {
            int u, x;
            std::cin >> u >> x;
            u--;

            dfs(dfs, u, x);
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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