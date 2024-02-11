#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;

    auto norm = [&](int &x)
    {
        if (x > n / 2)
            x = n + 1 - x;
    };

    norm(x1);
    norm(x2);
    norm(y1);
    norm(y2);
    
    auto get = [&](int x, int y)    
    {
        int limit = (n / 2 - x + 1);
        limit = n / 2 - limit;
        if (y <= limit)
            return y;
        return limit + 1;
    };
    
    std::cout << std::abs(get(x1, y1) - get(x2, y2)) << "\n";
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