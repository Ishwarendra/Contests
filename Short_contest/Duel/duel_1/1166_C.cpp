#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
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
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        a[i] = std::abs(a[i]);
    }

    std::sort(std::begin(a), std::end(a));

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = std::upper_bound(std::begin(a) + i + 1, std::end(a), 2 * a[i]);
        if (it <= std::begin(a) + i + 1)
            continue;

        it--;
        print(it - std::begin(a), *it)
        ans += it - (std::begin(a) + i);
    }

    std::cout << ans << "\n";
    
    return 0;
}