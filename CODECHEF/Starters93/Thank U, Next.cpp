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
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector mail(k, std::array<int, 2>());
    for (int i = 0; i < k; i++)
    {
        std::cin >> mail[i][0];
        mail[i][0]--;
    }
    for (int i = 0; i < k; i++)
        std::cin >> mail[i][1];

    std::vector<std::vector<int>> adj(n);  
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::set<std::pair<int, int>, std::greater<>> q;
    std::vector<int> d(n, -inf);
    for (int i = 0; i < k; i++)
    {
        q.emplace(mail[i][1] - 1, mail[i][0]);
        d[mail[i][0]] = mail[i][1] - 1;
    }

    while (!q.empty())
    {
        auto [dist, u] = *std::begin(q);
        q.erase(std::begin(q));

        if (dist == 0)
            continue;

        for (auto v : adj[u])
        {
            if (dist - 1 > d[v])
            {
                q.erase({d[v], v});
                d[v] = dist - 1;
                q.emplace(d[v], v);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (d[i] == -inf)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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