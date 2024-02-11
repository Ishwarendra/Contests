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

    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> query;
    std::map<int, std::vector<std::pair<int, int>>, std::greater<>> m;
    std::vector bit(n, std::vector<int>(31, -1));

    auto getBit = [](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    while (q--)
    {
        int i, j, x;
        std::cin >> i >> j >> x;
        i--, j--;
        query.push_back({i, j, x});

        int min = std::min(i, j);
        int max = std::max(i, j);

        m[max].emplace_back(min, x);
    }

    if (q == 0)
    {
        for (int i = 0; i < n; ++i)
            std::cout << 0 << " \n"[i == n - 1];

        return 0;
    }

    for (auto [j, p] : m)
    {
        for (auto [i, x] : p)
        {
            for (int pos = 29; pos >= 0; pos--)
            {
                if (!getBit(x, pos))
                    bit[i][pos] = bit[j][pos] = 0;
                else if (bit[j][pos] != 0)
                {
                    if (getBit(x, pos))
                        bit[j][pos] = 1;                    
                }
                else
                    bit[i][pos] = 1;    
            }
        }
    }

    std::vector<int> a;
    for (auto p : bit)
    {
        int num = 0;
        for (int i = 0; i < 30; i++)
        {
            if (p[i] == 1)
                num = num | (1 << i);
        }

        a.emplace_back(num);
        std::cout << num << " ";
    }

    for (auto p : query)
        assert(a[p[0]] | a[p[1]] == p[2]);

    return 0;
}