#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n, m, x, y;
    std::cin >> n >> m >> x >> y;

    std::cout << std::max({(n - x) * m, (x - 1) * m, (y - 1) * n, (m - y) * n}) << "\n";  
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