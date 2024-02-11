#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto bfs = [&](int src)
    {
        std::vector<int> d(n, inf);
        d[src] = 0;
        std::queue<int> q({src});

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] == inf)
                {
                    d[v] = d[u] + 1;
                    q.emplace(v);
                }
            }
        }

        return d;
    };

    auto d0 = bfs(0);
    int u = std::max_element(std::begin(d0), std::end(d0)) - std::begin(d0);
    auto du = bfs(u);

    int t = std::max_element(std::begin(du), std::end(du)) - std::begin(du);
    auto dt = bfs(t);

    int dia = du[t];
    int ans = 0;

    for (int i = 0; i < n; i++)
        du[i] = std::max(du[i], dt[i]);

    int max = std::count(std::begin(du), std::end(du), dia);
    int max2 = std::count(std::begin(du), std::end(du), dia - 1);

    std::cout << 1LL * max * (2 * n - max + 2) + 2 * max2 << "\n";
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