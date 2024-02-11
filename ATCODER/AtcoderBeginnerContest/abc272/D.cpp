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
    
    int n, m;
    std::cin >> n >> m;

    constexpr int inf = 1e9;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, inf));
    a[0][0] = 0;

    std::set<std::array<int, 2>> jumps;
    for (int a = 0; a <= 1e3; a++)
    {
        for (int b = 0; b <= 1e3; b++)
        {
            if (a * a + b * b == m)
            {
                jumps.insert({a, b});
                jumps.insert({-a, b});
                jumps.insert({a, -b});
                jumps.insert({-a, -b});
                jumps.insert({b, a});
                jumps.insert({-b, a});
                jumps.insert({b, -a});
                jumps.insert({-b, -a});
            }
        }
    }
    
    std::multiset<std::array<int, 3>> q;
    q.insert({0, 0, 0}); // distance, i, j

    std::vector<std::vector<int>> vis(n, std::vector<int>(n));
    vis[0][0] = 0;    

    auto safe = [&](int x, int y)
    {
        return x >= 0 and y >= 0 and x < n and y < n;
    };

    while (!q.empty())
    {
        auto [dist, x, y] = *std::begin(q);
        q.erase(std::begin(q));
        assert(dist != -1);

        for (auto [dx, dy] : jumps)
        {
            if (safe(x + dx, y + dy) and a[x + dx][y + dy] > a[x][y] + 1)
            {
                vis[x + dx][y + dy] = 1;
                a[x + dx][y + dy] = a[x][y] + 1;
                q.insert({a[x][y] + 1, x + dx, y + dy});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << (a[i][j] == inf ? -1 : a[i][j]) << " \n"[j == n - 1];
    }
}