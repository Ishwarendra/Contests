#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

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

    std::vector<int> options;
    for (int i = 1; 1LL * i * i <= a[0][0]; i++)
    {
        if (a[0][0] % i == 0)
        {
            options.emplace_back(i);
            options.emplace_back(a[0][0] / i);
        }
    }

    auto safe = [&](int i, int j)
    {
        return 0 <= i and i < n and 0 <= j and j < m;
    };

    auto work = [&](int g)
    {
        std::vector vis(n, std::vector(m, 0));
        vis[0][0] = 1;

        std::queue<std::pair<int, int>> q;
        q.emplace(0, 0);

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (safe(x + 1, y) and !vis[x + 1][y] and a[x + 1][y] % g == 0)
            {
                vis[x + 1][y] = 1;
                q.emplace(x + 1, y);
            }

            if (safe(x, y + 1) and !vis[x][y + 1] and a[x][y + 1] % g == 0)
            {
                vis[x][y + 1] = 1;
                q.emplace(x, y + 1);
            }
        }


        return vis[n - 1][m - 1];
    };

    std::sort(std::rbegin(options), std::rend(options));
    for (auto x : options)
    {
        if (work(x))
        {
            std::cout << x << '\n';
            return;
        }
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