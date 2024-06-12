#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
        
    if (a > b)
        std::swap(a, b);
    
    auto f = [&](int x, int y)
    {
        int ok = (x >= b and x <= 12) or (x <= a);
        ok &= (a < y and y < b);
        return ok;
    };
    
    std::cout << (f(c, d) || f(d, c) ? "YES\n" : "NO\n");
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