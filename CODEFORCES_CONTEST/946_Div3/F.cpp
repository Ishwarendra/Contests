#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;

    std::set<std::pair<int, int>> chipx, chipy;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        chipx.emplace(x, y);
        chipy.emplace(y, x);
    }

    auto updateRow = [&](int sx, int ex)
    {
        auto it = chipx.lower_bound({sx, -1});
        std::vector<std::pair<int, int>> del;
        int res = 0;
        for (; it != std::end(chipx); it++)
        {
            auto [x, y] = *it;
            if (x > ex)
                break;
            del.emplace_back(x, y);
            res++;
        }
        
        for (auto [x, y] : del)
        {
            chipx.erase({x, y});
            chipy.erase({y, x});
        }
        
        return res;
    };

    auto updateCol = [&](int sy, int ey)
    {
        auto it = chipy.lower_bound({sy, -1});
        std::vector<std::pair<int, int>> del;
        int res = 0;
        
        for (; it != std::end(chipy); it++)
        {
            auto &[y, x] = *it;
            if (y > ey)
                break;
            del.emplace_back(x, y);
            res++;
        }
        
        for (auto [x, y] : del)
        {
            chipx.erase({x, y});
            chipy.erase({y, x});
        }
        
        return res;
    };

    int sx = 1, sy = 1, ex = a, ey = b;
    std::array<int, 2> score{};
    int turn = 0;
    
    while (m--)
    {
        char ch;
        int k;
        std::cin >> ch >> k;

        if (ch == 'U')
        {
            score[turn] += updateRow(sx, sx + k - 1);
            sx += k;
        }
        else if (ch == 'D')
        {
            score[turn] += updateRow(ex - k + 1, ex);
            ex -= k;
        }
        else if (ch == 'L')
        {
            score[turn] += updateCol(sy, sy + k - 1);
            sy += k;
        }
        else
        {
            score[turn] += updateCol(ey - k + 1, ey);
            ey -= k;
        }
        
        turn ^= 1;
    }
    
    std::cout << score[0] << " " << score[1] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}