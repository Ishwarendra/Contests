#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> adj[n];

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int k;
        std::cin >> k;

        std::set<int> p;
        for (int i = 0; i < n; ++i)
        {
            int x;
            std::cin >> x;

            p.emplace(x);
        }

        std::vector<int> vis(n);
        std::set<int> found;
        std::function<int(int)> dfs;
        dfs = [&](int u) -> int
        {
            vis[u] = 1;
            if (p.count(u))
                found.emplace(u);

            int leaf = 1;

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    leaf = 0;
                    dfs(v);
                }
            }

            if (leaf)
            {
                if (std::size(found) == k)
                    return 1;
                else
                {
                    found.erase(u);
                    return 0;
                }
            }
        }
    }

    return 0;
}