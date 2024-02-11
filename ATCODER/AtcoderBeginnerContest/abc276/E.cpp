#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::array<int, 2> start;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'S')
                start = {i, j};
        }
    }

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m and a[i][j] != '#';
    };

    std::vector<std::vector<int>> vis(n, std::vector<int>(m));
    std::function<void(int, int, int, int)> dfs;
    bool can[2]{};

    dfs = [&](int i, int j, int pi, int pj)
    {
        vis[i][j] = 1;
        for (auto [dx, dy] : dirs)
        {
            if (!safe(i + dx, j + dy))
                continue;

            if (!vis[i + dx][j + dy])
                dfs(i + dx, j + dy, i, j);
            else if (a[i + dx][j + dy] == 'S' and (i + dx != pi or j + dy != pj))
                can[1] = 1;
        }

    }; dfs(start[0], start[1], -1, -1);

    if (can[1])
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    
    return 0;
}