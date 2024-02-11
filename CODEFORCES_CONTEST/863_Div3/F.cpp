#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> deg(n);
    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }

    std::vector<int> vis(n);
    std::function<void(int, int, int &)> dfs = [&](int u, int need, int &have)
    {
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (deg[v] == need and !vis[v])
                dfs(v, need, ++have);
        }
    };

    int c = std::count(std::begin(deg), std::end(deg), 4);
    int d = std::count(std::begin(deg), std::end(deg), 2);

    if (d == 1LL * c * (c - 1) and c + d == n and c >= 3)
    {
        for (int u = 0; u < n; u++)
        {
            if (deg[u] == 4)
            {
                std::array<int, 5> count{};
                for (int v : adj[u])
                    count[deg[v]]++;

                if (count[4] != 2 or count[2] != 2)
                {
                    std::cout << "NO\n";
                    return;
                }
            }
        }

        int root = std::find(std::begin(deg), std::end(deg), 4) - std::begin(deg);
        int have = 1;
        dfs(root, 4, have);

        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 4 and !vis[i])
            {
                std::cout << "NO\n";
                return;
            }

            if (deg[i] == 4)
            {
                have = 1;
                dfs(i, 2, have);
                if (have != c)
                {
                    std::cout << "NO\n";
                    return;
                }
            }
        }

        std::cout << "YES\n";
    }
    else
        std::cout << "NO\n";
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