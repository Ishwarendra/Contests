#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (n % 2)
    {
        i64 sum = 0;
        for (int i = 0, sign = 1; i < n; i++, sign = -sign)
            sum += sign * a[i];

        int ok = sum % 2 == 0 and sum >= 0;
        sum /= 2;
        for (int i = 0; i < n; i++)
        {
            i64 nsum = a[i] - sum;
            ok &= nsum >= 0;
            std::swap(nsum, sum);
        }

        std::cout << (ok ? "YES\n" : "NO\n");
    }
    else
    {
        i64 sum = 0, min = -1e18, max = 1e18;
        for (int i = 0; i < n; i++)
        {
            int sign = (i % 2 ? -1 : 1);
            sum += sign * a[i];
            
            if (i % 2 == 0)
                max = std::min(max, sum);
            else
                min = std::max(min, sum);
        }

        if (min >= 0 and min <= max and sum == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
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