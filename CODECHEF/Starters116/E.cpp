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

    std::vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    auto swap = [&](int i, int j)
    {
        std::swap(pos[a[i]], pos[a[j]]);
        std::swap(a[i], a[j]);
    };

    std::vector<std::vector<int>> ans;
    while (!std::is_sorted(std::begin(a), std::end(a)))
    {
        ans.emplace_back();
        auto &q = ans.back();

        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == i)
                continue;

            adj[i].emplace_back(a[i]);
        }

        std::vector<int> vis(n);
        auto dfs = [&](auto && self, int u, int swap) -> void
        {
            vis[u] = 1;
            for (int v : adj[u])
            {
                if (vis[v])
                    continue;

                if (swap)
                {
                    q.emplace_back(u);
                    q.emplace_back(v);
                }
                self(self, v, 1 - swap);
            }
        };

        for (int i = 0; i < n; i++)
        {
            if (!vis[i] and a[i] != i)
                dfs(dfs, i, 1);
        }

        for (int i = 0; i + 1 < std::size(q); i += 2)
            swap(q[i], q[i + 1]);

    }

    std::cout << std::size(ans) << "\n";
    int limit = std::__lg(n);
    if ((1 << limit) != n)
        limit++;
    assert(std::size(ans) <= limit);
    for (auto p : ans)
    {
        std::cout << std::size(p) << " ";
        for (int x : p)
            std::cout << x + 1 << " ";
        std::cout << "\n";
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