#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int l, r, x, a, b;
    std::cin >> l >> r >> x >> a >> b;

    if (a == b)
        std::cout << "0\n";
    else if (std::abs(a - b) >= x)
        std::cout << "1\n";
    else
    {
        if (a > b)
        {
            if (l <= b - x or a + x <= r)
                std::cout << "2\n";
            else if (l <= a - x and b + x <= r)
                std::cout << "3\n";
            else
                std::cout << "-1\n";
        }
        else
        {
            if (l <= a - x or b + x <= r)
                std::cout << "2\n";
            else if (l <= b - x and a + x <= r)
                std::cout << "3\n";
            else
                std::cout << "-1\n";
        }
    }
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