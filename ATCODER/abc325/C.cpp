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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto safe = [&](int i, int j)
    {
        return i >= 0 and i < n and j >= 0 and j < m and a[i][j] != '.';
    };

    int ans = 0;
    auto bfs = [&](int x, int y)
    {
        std::queue<std::pair<int, int>> q;
        q.emplace(x, y);
        a[x][y] = '.';
        ans++;

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (!safe(i + dx, j + dy))
                        continue;

                    q.emplace(i + dx, j + dy);
                    a[i + dx][j + dy] = '.';
                }
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
                bfs(i, j);
        }
    }

    std::cout << ans;

    return 0;
}