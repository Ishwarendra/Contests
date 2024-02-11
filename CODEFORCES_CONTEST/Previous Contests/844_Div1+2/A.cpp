#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int w, d, h, a, b, f, g;
    std::cin >> w >> d >> h >> a >> b >> f >> g;

    int ans = 1e9;

    auto get = [&]()
    {
        if (f + a <= w - f + w - a)
            return f + h + a + std::abs(b - g);

        return 2 * w + h + std::abs(b - g) - a - f;
    };

    for (int i = 0; i < 2; i++)
    {
        ans = std::min(ans, get());

        std::swap(a, b);
        std::swap(f, g);
        std::swap(w, d);
    }

    std::cout << ans << "\n";
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