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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    auto marked = [&](int x) { return std::binary_search(std::begin(a), std::end(a), x); };
    std::vector<int> adj[n];
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
        std::queue<int> q;
        std::vector<int> d(n, inf);
        d[src] = 0;
        q.emplace(src);

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] != inf)
                    continue;

                d[v] = d[u] + 1;
                q.emplace(v);
            }
        }

        return d;
    };

    auto ds = bfs(a[0]);
    std::array<int, 2> max{};
    for (int i = 0; i < n; i++)
    {
        if (marked(i))
            max = std::max(max, std::array{ds[i], i});
    }

    auto dt = bfs(max[1]);
    int dia = 0;
    for (int i = 0; i < n; i++)
    {
        if (marked(i))
            dia = std::max(dia, dt[i]);
    }

    std::cout << (dia + 1) / 2 << "\n";
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