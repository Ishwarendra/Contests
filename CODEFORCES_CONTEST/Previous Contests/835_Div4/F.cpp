#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string impossible = "Impossible";
std::string infinity = "Infinity";

void solve()
{
    int n, d;
    i64 c;
    std::cin >> n >> c >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a), std::greater());
    if (a[0] * 1LL * d < c)
    {
        std::cout << impossible << "\n";
        return;
    }

    i64 sum = std::accumulate(std::begin(a), std::begin(a) + std::min(n, d), 0LL);
    if (sum >= c)
    {
        std::cout << infinity << "\n";
        return;
    }

    auto good = [&](auto mid, int d)
    {
        mid++;
        i64 sum = std::accumulate(std::begin(a), std::begin(a) + std::min<i64>(mid, n), 0LL);
        i64 sum_2 = std::accumulate(std::begin(a), std::begin(a) + std::min<i64>(d % mid, n), 0LL);
        
        i64 max = sum * (d / mid) + sum_2;
        
        return max >= c;
    };

    int left = 0, right = 1e9;
    int ans = 0;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid, d))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
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