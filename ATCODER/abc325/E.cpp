#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 4e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    std::vector d(n, std::vector(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cin >> d[i][j];
    }

    auto car = [&](int i, int j)
    {
        return 1LL * d[i][j] * a;
    };

    auto train = [&](int i, int j)
    {
        return 1LL * d[i][j] * b + c;
    };

    auto bfs = [&](std::function<i64(int, int)> dist, int src)
    {
        std::set<std::pair<i64, int>> s;
        std::vector<i64> ans(n, inf);
        ans[src] = 0;

        s.emplace(ans[src], src);
        while (!s.empty())
        {
            auto [du, u] = *std::begin(s);
            s.erase(std::begin(s));

            for (int v = 0; v < n; v++)
            {
                if (ans[v] > ans[u] + dist(u, v))
                {
                    s.erase({ans[v], v});
                    ans[v] = dist(u, v) + ans[u];
                    s.emplace(ans[v], v);
                }
            }
        }

        return ans;
    };      

    auto ds = bfs(car, 0);
    auto dt = bfs(train, n - 1);

    i64 ans = inf;
    for (int i = 0; i < n; i++)
        ans = std::min(ans, ds[i] + dt[i]);

    std::cout << ans;
    return 0;
}