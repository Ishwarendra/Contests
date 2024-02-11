#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template<typename T = int, typename G = double>
G sqroot(T x, long double eps = 1e-9)
{
    G left = 0, right = x;

    while (right - left > eps)
    {
        G mid = left + (right - left) / 2;

        if (mid >= x / mid)
            right = mid;
        else
            left = mid;
    }

    return left + (right - left) / 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(18);
    const long double tan60 = 1.73205080757L;
    constexpr long double eps = 1e-12;

    auto ans = [&](int l, int w)
    {
        const long double a2 = l * l + (2.0L * w - l * tan60) * (2.0L * w - l * tan60);
        return sqroot<long double, long double>(a2, eps);
    };

    int l, w;
    std::cin >> l >> w;

    if (l < w)
        std::swap(l, w);

    if (l > w * 2 / tan60)
        std::cout << w * 2 / tan60;
    else
        std::cout << ans(l, w);

    return 0;
}
