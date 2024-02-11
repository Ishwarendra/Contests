#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    auto get = [&](int x, int y)
    {
        if (y % 2)
            return false;

        y /= 2;
        return x != y;
    };

    std::cout << (get(a, b) || get(b, a) ? "Yes\n" : "No\n");
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