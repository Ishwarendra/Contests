#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

auto rev(auto &x)
{
    std::reverse(std::begin(x), std::end(x));
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::string _;
    std::cin >> _;
    rev(_);

    int initial = 0;
    for (int i = 0; i < n; i++)  
    {
        auto ch = _[i];
        if (ch == '1')
            initial |= (1 << i);
    }

    print(initial)

    std::vector<std::pair<int, int>> adj[1 << n];
    for (int i = 0; i < m; i++)
    {
        int d;
        std::string cure_, give_;
        std::cin >> d >> cure_ >> give_;
        rev(cure_);
        rev(give_);

        int cure = 0, give = 0;
        for (int pos = 0; pos < n; pos++)
        {
            if (cure_[pos] == '0')
                cure |= (1 << pos);
            if (give_[pos] == '1')
                give |= (1 << pos);
        }

        for (int u = 0; u < (1 << n); u++)
        {
            int v = u & cure;
            v |= give;
            adj[u].emplace_back(v, d);
        }
    }

    constexpr i64 inf = 1e18;
    auto dijkstra = [&](int src)
    {
        std::set<std::pair<i64, int>> q;
        q.emplace(0LL, src);
        std::vector<i64> d(1 << n, inf);
        d[src] = 0;

        while (!q.empty())
        {
            auto [d_, u] = *std::begin(q);
            q.erase(std::begin(q));

            for (auto [v, w] : adj[u])
            {
                if (d[v] > d[u] + w and d[u] != inf)
                {
                    print(u, v)
                    q.erase(std::pair<i64, int>{d[v], v});
                    d[v] = d[u] + w;
                    q.emplace(d[v], v);
                }
            }
        }

        return d;
    };

    auto d = dijkstra(initial);
    std::cout << (d[0] < inf ? d[0] : -1) << "\n";
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