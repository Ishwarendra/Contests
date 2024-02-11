#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 get(int n) { return 1LL * n * n; }

void solve()
{
    i64 sum;
    std::cin >> sum;

    i64 left = 0, right = 1e9;
    i64 ans = 0;

    auto f = [&](int x) { return 2 * x; };
    auto g = [&](int x) { return 2 * x - 1; };

    auto good = [&](i64 mid)
    {
        auto s = get(mid);
        if (sum - s > 2 * mid - 1)
            return true;
        return false;
    };

    while (left <= right)
    {
        i64 mid = (left + right) / 2;
        if (good(sum % 2 == 0 ? g(mid) : f(mid)))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans + (sum % 2) << "\n";
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