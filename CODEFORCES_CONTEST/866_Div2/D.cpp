#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::array {0, 0});
    int max_h = 0, max_w = 0;

    i64 area = 0;
    for (auto &[x, y] : a)
    {
        std::cin >> x >> y;
        max_h = std::max(max_h, x);
        max_w = std::max(max_w, y);
        area += 1LL * x * y;
    }   

    auto erase = [&](auto &m, auto x)
    {
        m.erase(m.find(x));
    };

    auto get = [&](i64 h, i64 w, auto find)
    {
        std::map<i64, std::multiset<i64>, std::greater<>> height, width;
        for (auto &[x, y] : a)
        {
            height[x].emplace(y);
            width[y].emplace(x);
        }

        int count = 0;
        while (find[0] > 0 || find[1] > 0)
        {
            if (find[0] > 0)
            {
                if (height[find[0]].empty())
                    break;

                while (!height[find[0]].empty())
                {   
                    int temp_w = *std::begin(height[find[0]]);
                    w -= temp_w;
                    erase(width[temp_w], find[0]);
                    erase(height[find[0]], temp_w);

                    count++;
                }

                find[0] = 0;
                find[1] = w;
            }
            else
            {
                if (width[find[1]].empty())
                    break;

                while (!width[find[1]].empty())
                {
                    int temp_h = *std::begin(width[find[1]]);
                    h -= temp_h;
                    erase(height[temp_h], find[1]);
                    erase(width[find[1]], temp_h);

                    count++;
                }

                find[0] = h;
                find[1] = 0;
            }
        }

        return count == n;
    };

    auto possible = [&](auto h, auto w, bool height = true)
    {
        return get(h, w, std::array<i64, 2>{0, w}) || get(h, w, std::array<i64, 2>{h, 0});
    };

    std::set<std::pair<i64, i64>> ans;
    print(area, max_h, max_w)
    if (area % max_h == 0 and possible(max_h, area / max_h))
        ans.emplace(max_h, area / max_h);
    if (area % max_w == 0 and possible(area / max_w, max_w, false))
        ans.emplace(area / max_w, max_w);

    std::cout << std::size(ans) << "\n";
    for (auto &[x, y] : ans)
        std::cout << x << " " << y << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}