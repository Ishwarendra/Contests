#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, l;
    std::cin >> n >> m >> l;

    std::vector<int> a(n);
    std::vector<std::array<int, 2>> b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i][0];
        b[i][1] = i;
    }

    std::sort(std::rbegin(b), std::rend(b));

    std::vector<std::vector<int>> adj(std::max(n, l));
    while (l--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[--u].emplace_back(--v);
    }

    for (int i = 0; i < std::size(adj); i++)
        std::sort(std::begin(adj[i]), std::end(adj[i]));

    auto in = [&](auto &p, int x)
    {
        return std::binary_search(std::begin(p), std::end(p), x);
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (in(adj[i], b[j][1]))
                continue;

            ans = std::max(ans, a[i] + b[j][0]);
            break;
        }
    }

    std::cout << ans;

    return 0;
}
