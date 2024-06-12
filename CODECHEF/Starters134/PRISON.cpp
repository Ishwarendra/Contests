#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

std::vector<std::pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; i++)  
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';
    }

    std::set<std::tuple<int, int, int>> q;
    std::vector dist(n, std::vector(m, inf));
    for (int i = 0; i < m; i++)
    {
        q.emplace(a[0][i], 0, i);
        q.emplace(a[n - 1][i], n - 1, i);
        dist[0][i] = a[0][i];
        dist[n - 1][i] = a[n - 1][i];
    }
    
    for (int i = 0; i < n; i++)
    {
        q.emplace(a[i][0], i, 0);
        q.emplace(a[i][m - 1], i, m - 1);
        dist[i][0] = a[i][0];
        dist[i][m - 1] = a[i][m - 1];
    }
    
    auto safe = [&](int i, int j)
    {
        return 0 <= i and i < n and 0 <= j and j < m;
    };
    
    while (!q.empty())
    {
        auto [d, x, y] = *std::begin(q);
        q.erase(std::begin(q));
        
        for (auto &[dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy))
                continue;
            
            if (dist[x + dx][y + dy] > d + a[x + dx][y + dy])
            {
                q.erase({dist[x + dx][y + dy], x + dx, y + dy});
                dist[x + dx][y + dy] = d + a[x + dx][y + dy];
                q.emplace(dist[x + dx][y + dy], x + dx, y + dy);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                ans = std::max(ans, dist[i][j]);
        }
    }
    
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