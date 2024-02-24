#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n, m, l, x0, y0;
    std::cin >> n >> m >> x0 >> y0 >> l;

    auto get = [&](i64 x, i64 L, i64 n)
    {
        // print((n - x) / l, (x - 1) / l)
        return (n - x) / l + (x - 1) / l + 1;
    };

    std::cout << get(x0, l, n) * get(y0, l, m) << "\n";
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