#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;

void solve()
{
    int n;
    i64 c;
    std::cin >> n >> c;  

    std::vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
        c -= s[i] * s[i];
    }

    c = -c;
    int sum = std::accumulate(std::begin(s), std::end(s), 0);

    auto good = [&](i64 mid)
    {
        i128 lhs = i128(n) * mid * mid; 
        lhs += i128(sum) * (2 * mid);
        lhs += c;

        return lhs >= 0;
    };

    i64 left = 0, right = 2e9;
    int ans = -1;

    while (left <= right)
    {
        auto mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans / 2 << "\n";
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