#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    auto f = [&](auto f, auto now, auto l, auto r, auto bit)
    {
        if (bit == -1)
            return 0;

        int m = std::lower_bound(std::begin(a) + l, std::begin(a) + r + 1, now | (1 << bit)) - std::begin(a);
        if (m == r + 1)
            return f(f, now, l, m - 1, bit - 1);
        else if (m == l)
            return f(f, now | (1 << bit), m, r, bit - 1);
        else
            return std::min(f(f, now, l, m - 1, bit - 1), f(f, now | (1 << bit), m, r, bit - 1)) | (1 << bit);
    };

    std::cout << f(f, 0, 0, n - 1, 30);

    return 0;
}