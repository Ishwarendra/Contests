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

    auto rotate = [&]()
    {
        int temp = a;
        a = c;
        c = d;
        d = b;
        b = temp;
    };

    auto check = [&]()
    {
        return a < c and b < d and a < b and c < d;
    };

    for (int i = 0; i < 8; i++)
    {
        if (check())
        {
            std::cout << "YES\n";
            return;
        }

        rotate();
    }

    std::cout << "NO\n";
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