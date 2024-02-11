#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    --a, --b;

    std::vector<std::pair<int, int>> adj[n];

    for (int i = 0; i < n - 1; i++)  
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        v--, u--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::function<void(int, int, int, std::vector<int> &)> dfs;
    dfs = [&](int u, int p, int ignore, std::vector<int> &xor_sum)
    {
        for (auto [v, w] : adj[u])
        {
            if (v == p or v == ignore)
                continue;

            xor_sum[v] = xor_sum[u] ^ w;
            dfs(v, u, ignore, xor_sum);
        }
    };

    std::vector xa(n, -1), xb(n, -1);
    xa[a] = 0, xb[b] = 0;
    dfs(a, a, b, xa);
    dfs(b, b, -1, xb);

    if (xb[a] == 0)
        std::cout << "YES\n";
    else
    {
        std::set<int> options;
        for (int i = 0; i < n; i++)
        {
            if (i == b or xa[i] == -1)
                continue;

            options.emplace(xa[i]);
        }

        std::vector<int> from_b;
        for (int i = 0; i < n; i++)
        {
            if (i == a or i == b)
                continue;
            
            from_b.emplace_back(xb[i]);
        }
        for (auto p : from_b)
        {
            if (options.count(p))
            {
                std::cout << "YES\n";
                return;
            }
        }

        std::cout << "NO\n";
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