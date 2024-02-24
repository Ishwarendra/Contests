#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
std::vector<int> masks[22];

void solve()
{
    const int n = 7;  
    std::string a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto safe = [&](int i, int j) 
    {
        return i >= 0 and i < n and j >= 0 and j < n;
    };

    auto bad = [&](int x, int y)
    {
        if (a[x][y] == 'W')
            return false;

        for (auto &[dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy))
                return false;
            if (a[x + dx][y + dy] == 'W')
                return false;
        }

        return true;
    };

    i64 which[n][n]{};
    int cnt = 0;

    std::vector<std::array<int, 2>> ids;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (!bad(i, j))
                continue;

            which[i][j] |= 1 << cnt;
            for (auto &[dx, dy] : dirs)
                which[i + dx][j + dy] |= 1 << cnt;
            cnt++;
        }
    }

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if ((i == 1 || i == n - 2) and (j == 1 || j == n - 2))
                continue;
            ids.push_back({i, j});
        }
    }    

    for (int len = 0; len < 22; len++)
    {
        for (int mask : masks[len])
        {
            i64 rem = 0;
            for (int i = 0; i < 21; i++)
            {
                if (getBit(mask, i))
                    rem |= which[ids[i][0]][ids[i][1]];
            }

            if (rem == (1 << cnt) - 1)
            {
                std::cout << __builtin_popcount(mask) << "\n";
                return;
            }
        }
    }

    std::cout << cnt << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int mask = 0; mask < (1 << 21); mask++)
        masks[__builtin_popcount(mask)].emplace_back(mask);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}