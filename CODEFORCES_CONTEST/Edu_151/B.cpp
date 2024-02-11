#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::array<int, 2> a{}, b{}, c{};       
    std::cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];

    i64 ans = 0;
    auto same = [&](int x1, int x2, int a)
    {
        return 1LL * (x1 - a) * (x2 - a) >= 0;
    };

    if (same(b[0], c[0], a[0]))
        ans += std::min(std::abs(b[0] - a[0]), std::abs(c[0] - a[0]));

    if (same(b[1], c[1], a[1]))   
        ans += std::min(std::abs(b[1] - a[1]), std::abs(c[1] - a[1]));
    std::cout << ans + 1 << "\n";
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