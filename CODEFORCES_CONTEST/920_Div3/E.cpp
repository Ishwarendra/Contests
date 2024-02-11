#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, xa, xb, ya, yb;
    std::cin >> n >> m >> xa >> ya >> xb >> yb;

    auto safe = [&](int x, int y)
    {
        return 1 <= x and x <= n and 1 <= y and y <= m;
    };

    auto f = [&](int xa, int ya, int xb, int yb, bool alice_draw = false)
    {
        // 1 -> alice, 2 -> bob, 0 -> draw
        if (!safe(xa, ya) or !safe(xb, yb))
            return 3;

        if (xa == xb and ya == yb)
            return 2;
        if (xa > xb)
            return 0;

        int mid = (xb + xa) / 2;

        std::array<int, 2> alice{}, bob{};
        alice[0] = std::max(1, ya - std::abs(xa - mid));
        alice[1] = std::min(m, ya + std::abs(xa - mid));

        bob[0] = std::max(1, yb - std::abs(xb - mid));
        bob[1] = std::min(m, yb + std::abs(xb - mid));

        auto in = [&](auto &a, auto &b)
        {
            return a[0] <= b[0] and b[1] <= a[1];
        };

        if (!alice_draw and !in(alice, bob))
            return 0;
            
        if (alice_draw and !in(bob, alice))
            return 0;

        return 2;
    };

    if (xa >= xb)
        std::cout << "Draw\n";
    else if ((xb - xa) % 2 == 0)
    {
        // bob trying to win
        for (int d : {-1, 0, 1})
        {
            if (f(xa + 1, ya + d, xb, yb, true) == 0)
            {
                std::cout << "Draw\n";
                return;
            }
        }

        std::cout << "Bob\n";
    }
    else
    {
        // alice trying to win
        for (int d : {-1, 0, 1})
        {
            // print(f(xa + 1, ya + d, xb, yb), xa + 1, ya - 1)
            if (f(xa + 1, ya + d, xb, yb) == 2)
            {
                std::cout << "Alice\n";
                return;
            }
        }

        std::cout << "Draw\n";
    }
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