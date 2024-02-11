#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x1, y1;
    std::cin >> x1 >> y1;

    auto dist = [&](int x, int y, int x2, int y2)
    {
        return std::abs(x - x2) + std::abs(y - y2);
    };

    for (int x = -100; x <= 100; x++)  
    {
        for (int y = -100; y <= 100; y++)
        {
            if (dist(0, 0, x, y) == dist(x, y, x1, y1))
            {
                std::cout << x << " " << y << "\n";
                return;
            }
        }
    }

    std::cout << "-1 -1\n";
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