#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    for (int x = a + 1; x <= c; x++)  
    {
        i64 y = (1LL * a * b) / std::gcd<i64>(1LL * a * b, x);
        i64 left = (b + 1 + y - 1) / y;
        i64 right = d / y;

        if (right - left + 1 > 0)
        {
            y *= left;
            assert ((a < x and x <= c and b < y and y <= d and ((1LL * x * y) % (1LL * a * b) == 0)));

            std::cout << x << " " << y << "\n";
            return;
        }
    }

    std::cout << "-1 -1\n";
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