#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int cnt, n, m;
    std::cin >> cnt >> n >> m;

    std::vector a(cnt, std::array<int, 2>());
    for (auto &[l, w] : a)
        std::cin >> l >> w;

    auto possible = [&](const std::vector<std::array<int, 2>> &tiles)
    {
        std::vector done(n, std::vector(m, 0));
        int id = 0;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (done[x][y])
                    continue;

                if (id == std::size(tiles))
                    return false;
                
                auto [l, w] = tiles[id++];
                if (y + l - 1 >= m or x + w - 1 >= n)
                    return false;

                for (int i = x; i < x + w; i++)
                {
                    for (int j = y; j < y + l; j++)
                    {
                        if (done[i][j])
                            return false;

                        done[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!done[i][j])
                    return false;
            }
        }

        return true;
    };

    auto check = [&](std::vector<std::array<int, 2>> tiles)
    {
        std::sort(std::begin(tiles), std::end(tiles));
        do
        {
            if (possible(tiles))
                return true;
        } while (std::next_permutation(std::begin(tiles), std::end(tiles)));

        return false;
    };

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    for (int mask1 = 1; mask1 < (1 << cnt); mask1++)
    {
        std::vector<std::array<int, 2>> tiles;

        for (int i = 0; i < cnt; i++)
        {
            if (getBit(mask1, i))
                tiles.emplace_back(a[i]);
        }

        int tot = std::size(tiles);

        for (int mask2 = 0; mask2 < (1 << tot); mask2++)
        {
            for (int i = 0; i < tot; i++)
            {
                if (getBit(mask2, i))
                    std::swap(tiles[i][0], tiles[i][1]);
            }

            if (check(tiles))
            {
                std::cout << "Yes";
                return 0;
            }

            for (int i = 0; i < tot; i++)
            {
                if (getBit(mask2, i))
                    std::swap(tiles[i][0], tiles[i][1]);
            }
        }
    }

    std::cout << "No";
    
    return 0;
}