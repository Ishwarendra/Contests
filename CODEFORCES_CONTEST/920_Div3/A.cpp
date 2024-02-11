#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    const int n = 4;
    std::array<int, 2> min {1000, 1000}, max {-1000, -1000};
    for (int i = 0; i < n; i++)  
    {
        int x, y;
        std::cin >> x >> y;
        min[0] = std::min(min[0], x);
        min[1] = std::min(min[1], y);
        max[0] = std::max(max[0], x);
        max[1] = std::max(max[1], y);
    }

    std::cout << (max[0] - min[0]) * (max[1] - min[1]) << "\n";
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