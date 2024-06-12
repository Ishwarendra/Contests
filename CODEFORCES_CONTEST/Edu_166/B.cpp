#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i <= n; i++)
        std::cin >> b[i];
    
    i64 ans = 1;
    int add = 1e9;
    
    auto between = [&](int x, int l, int r)
    {
        return l <= x and x <= r;
    };
    
    for (int i = 0; i < n; i++)
    {
        ans += std::abs(a[i] - b[i]);
        auto [min, max] = std::minmax(a[i], b[i]);
        if (between(b[n], min, max))
            add = 0;
        else
            add = std::min({add, std::abs(a[i] - b[n]), std::abs(b[i] - b[n])});
    }
    
    std::cout << ans + add << "\n";
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