#include <bits/stdc++.h>

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
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    auto safe = [&](int x, int y)
    {
        return x >= 0 and y >= 0 and x < n and y < m;
    };

    int dx, dy;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m));
    vis[0][0] = 1;

    int i = 0, j = 0;
    while (true)
    {
        if (a[i][j] == 'R')
        {
            dx = 0, dy = 1;
            if (!safe(i + dx, j + dy))
            {
                std::cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
            i += dx, j += dy;

            if (vis[i][j])
            {
                std::cout << "-1\n";
                return 0;
            }

            vis[i][j] = 1;
        }
        else if (a[i][j] == 'L')
        {
            dx = 0, dy = -1;
            if (!safe(i + dx, j + dy))
            {
                std::cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
            i += dx, j += dy;

            if (vis[i][j])
            {
                std::cout << "-1\n";
                return 0;
            }

            vis[i][j] = 1;
        }
        else if (a[i][j] == 'U')
        {
            dx = -1, dy = 0;
            if (!safe(i + dx, j + dy))
            {
                std::cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
            i += dx, j += dy;

            if (vis[i][j])
            {
                std::cout << "-1\n";
                return 0;
            }

            vis[i][j] = 1;
        }
        else
        {
            dx = 1, dy = 0;
            if (!safe(i + dx, j + dy))
            {
                std::cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
            i += dx, j += dy;

            if (vis[i][j])
            {
                std::cout << "-1\n";
                return 0;
            }

            vis[i][j] = 1;
        }
    }


    return 0;
}