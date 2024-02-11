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

    if (a[0][0] != 's')
    {
        std::cout << "No";
        return 0;
    }

    std::vector<std::array<int, 2>> dirs {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    const std::string t = "snuke";
    auto f = [&](char ch)
    {
        return std::find(std::begin(t), std::end(t), ch) - std::begin(t);
    };

    std::vector vis(n, std::vector(m, std::array<int, 6>()));
    vis[0][0][f(a[0][0])] = 1;

    std::queue<std::tuple<int, int, int>> q;
    q.emplace(0, 0, f(a[0][0]));

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m and f(a[i][j]) != 5;
    };

    while (!q.empty())
    {
        auto [x, y, id] = q.front();
        q.pop();    
        if (x == n - 1 and y == m - 1)
            break;

        for (auto [dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy))
                continue;

            if (vis[x + dx][y + dy][f(a[x + dx][y + dy])])
                continue;

            if (f(a[x + dx][y + dy]) == (id + 1) % 5)
            {
                vis[x + dx][y + dy][f(a[x + dx][y + dy])] = 1;
                q.emplace(x + dx, y + dy, f(a[x + dx][y + dy]));
            }
        }
    }

    int ok = 0;
    for (int i = 0; i < 5; i++)
        ok |= vis[n - 1][m - 1][i];

    std::cout << (ok ? "Yes" : "No");

    return 0;
}