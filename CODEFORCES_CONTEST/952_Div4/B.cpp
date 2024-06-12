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
    
    auto get = [&](int x) { return 1LL * x * (x + 1) / 2; };
    
    std::array<i64, 2> max { -1, -1 };
    for (int x = 2; x <= n; x++)  
        max = std::max(max, std::array<i64, 2> { get(n / x) * x, x });
    
    std::cout << max[1] << "\n";
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