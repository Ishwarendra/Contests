#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k1, k2, b, w;
    std::cin >> n >> k1 >> k2 >> w >> b;

    auto f = [&](int x, int y)
    {
        return std::min(x, y) + std::abs(x - y) / 2;
    };

    if (f(k1, k2) >= w and f(n - k1, n - k2) >= b)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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