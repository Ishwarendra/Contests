#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e5;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>());
    int ans = 0;
    for (auto &[x, y] : a)
    {
        std::cin >> x >> y;
        ans += x - y > 0;
    }

    std::cout << ans << "\n";
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