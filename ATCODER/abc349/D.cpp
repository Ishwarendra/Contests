#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 L, R;
    std::cin >> L >> R;

    auto cnt2 = [&](i64 x)
    {
        if (x == 0)
            return 60;
        int cnt = 0;
        while (x % 2 == 0)
            x /= 2, cnt++;
        return cnt;
    };

    std::vector<std::pair<i64, i64>> a;

    while (R - L > 0)
    {
        a.emplace_back(L, -1);
        i64 d = R - L + 1;
        int cnt = cnt2(L);

        int p = 0;
        while (p < cnt and (1LL << p) < d)
            p++;

        if (L + (1LL << p) > R)
            p--;

        L += 1LL << p;
        a.back().second = L;
    }

    std::cout << std::size(a) << "\n";
    for (auto &[l, r] : a)
        std::cout << l << " " << r << "\n";

    return 0;
}