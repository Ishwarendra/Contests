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

    int d = std::abs(a - b);
    int left = 0, right = d;
    int ans = 0;

    auto good = [&](int mid)
    {
        return 1LL * mid * (mid + 1) / 2 >= d;
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    auto par = [&](i64 x) { return x % 2; };
    while (par(1LL * ans * (ans + 1) / 2) != par(d))
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