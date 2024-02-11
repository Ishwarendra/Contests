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

    auto factors = [&](auto x)
    {
        std::vector<int> f(1, 1);

        for (int i = 2; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                f.emplace_back(i);
                if (1LL * i * i != x)
                    f.emplace_back(x / i);
            }
        }

        f.emplace_back(x);

        return f;
    };

    auto fa = factors(a), fb = factors(b);
    auto get = [&](auto x, auto l, auto r) -> i64
    {
        // l <= x * k <= r
        i64 left = (l + x - 1) / x;
        i64 right = r / x;

        if (right - left + 1 >= 0)
            return left;

        return -1;
    };

    for (int x : fa)
    {
        for (int y : fb)
        {
            i64 z = 1LL * x * y;
            i64 w = 1LL * (a / x) * (b / y);

            for (int _ : {0, 0})
            {
                auto q1 = get(z, a + 1, c);
                auto q2 = get(w, b + 1, d);

                z *= q1;
                w *= q2;

                if (a < z and z <= c and b < w and w <= d)
                {
                    std::cout << z << " " << w << "\n";
                    return;
                }

                z /= q1;
                w /= q2;

                std::swap(z, w);
            }
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