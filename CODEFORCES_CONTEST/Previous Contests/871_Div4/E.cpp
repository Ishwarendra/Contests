#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::array<int, 2>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    auto safe = [&](int x, int y)
    {
        return x >= 0 and y >= 0 and x < n and y < m and a[x][y] > 0;
    };

    i64 ans = 0;
    i64 sum = 0;

    std::function<void(int, int)> dfs = [&](int x, int y)
    {
        sum += a[x][y];
        a[x][y] = 0;

        for (auto [dx, dy] : dirs)
        {
            if (safe(x + dx, y + dy))
                dfs(x + dx, y + dy);
        }
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j])
            {
                sum = 0;
                dfs(i, j);
                ans = std::max(ans, sum);
            }
        }
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}