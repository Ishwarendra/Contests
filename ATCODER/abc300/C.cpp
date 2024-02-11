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

    auto bound = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    std::vector<std::array<int, 2>> dirs {{1, -1}, {1, 1}, { -1, 1}, { -1, -1}};
    std::vector<int> ans(n + 10);

    auto getSize = [&](int x, int y)
    {
        for (int i = 0; i <= n + 1; i++)
        {
            bool ok = true;
            for (auto [dx, dy] : dirs)
            {
                if (!bound(x + dx * i, y + dy * i) || a[x + dx * i][y + dy * i] == '.')
                    ok = false;
            }

            if (!ok)
                return i - 1;
        }

        return -1;
    };
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
                continue;

            int sz = getSize(i, j);

            if (sz >= 0)
                ans[sz]++;
        }
    }

    for (int i = 1; i <= std::min(n, m); i++)
        std::cout << ans[i] << " \n"[i == n];

    return 0;
}