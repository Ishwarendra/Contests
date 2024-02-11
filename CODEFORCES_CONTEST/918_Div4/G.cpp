#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;
constexpr int N = 1001;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)  
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::set<std::tuple<i64, int, int>> s;
    std::vector d(n, std::vector(N, inf));

    d[0][a[0]] = 0;
    s.emplace(0, a[0], 0);
    while (!s.empty())
    {
        auto [dis, f, u] = *std::begin(s);
        s.erase(std::begin(s));

        for (auto &[v, w] : adj[u])
        {
            i64 t = w * f;
            if (dis + t < d[v][std::min(f, a[v])])
            {
                s.erase({d[v][std::min(f, a[v])], std::min(f, a[v]), v});
                d[v][std::min(f, a[v])] = dis + t;
                s.emplace(d[v][std::min(f, a[v])], std::min(f, a[v]), v);
            }
        }
    }

    i64 ans = inf;
    for (int i = 0; i < N; i++)
        ans = std::min(ans, d[n - 1][i]);
    std::cout << ans << "\n";
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