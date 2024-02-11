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
    i64 k;
    std::cin >> n >> m >> k;

    std::vector a(n, std::vector<i64>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; ++j)
            std::cin >> a[i][j];
    }

    std::map<i64, int> first, second;
    int s = m;

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    i64 val = 0;
    std::function<void(int, int, int, int)> dfs;
    dfs = [&](int i, int j, int x, int y)
    {
        if (i == x and j == y)
        {
            first[val]++;
            return;
        }
        if (i + j == s - 1 or !safe(i, j))
            return;

        val ^= a[i][j];

        if (i + 1 + j <= s - 1)
            dfs(i + 1, j, x, y), dfs(i, j + 1, x, y);

        val ^= a[i][j];
    };

    std::function<void(int, int, int, int)> dfs2;
    dfs2 = [&](int i, int j, int x, int y)
    {
        if (i == x and j == y)
        {
            second[val]++;
            return;
        }
        if (i + j == s - 1 or !safe(i, j))
            return;

        val ^= a[i][j];

        if (i - 1 + j >= s - 1)
            dfs2(i - 1, j, x, y), dfs2(i, j - 1, x, y);

        val ^= a[i][j];
    };

    int i = 0, j = m - 1;
    i64 ans = 0;
    while (i < n and j >= 0)
    {   
        first.clear();
        second.clear();

        dfs(0, 0, i, j);
        dfs2(n - 1, m - 1, i, j);
        for (auto &[num, f] : first)
        {
            if (second.contains(num ^ a[i][j] ^ k))
                ans += 1LL * f * second[num ^ a[i][j] ^ k];
        }

        i++, j--;
    }

    std::cout << ans;

    return 0;
}