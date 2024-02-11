#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>());
    for (auto &[l, r] : a)
        std::cin >> l >> r;

    std::sort(std::begin(a), std::end(a), [&](auto x, auto y)
    {
        return x[1] < y[1];
    });

    std::array<int, 2> last {-1, -1};
    auto unset = [&]()
    {
        return last == std::array {-1, -1};
    };

    int ans = 0;
    int max = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i][0] <= max)
        {
            ans++;
            continue;
        }

        if (unset())
            last = a[i];
        else
        {
            if (a[i][0] <= last[1])
                last = {-1, -1}, max = a[i][1];
            else
                last = a[i], ans++;
        }
    }

    if (!unset())
        ans++;

    std::cout << ans << "\n";
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