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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    a.erase(std::unique(std::begin(a), std::end(a)), std::end(a));
    n = std::size(a);

    auto add = [&](auto &p, auto x)
    {
        if (std::size(p) > k)
            p.erase(--std::end(p));
        p.insert(x);
    };

    std::set<i64> s;
    s.emplace(0);

    while (k--)
    {
        auto cur = *std::begin(s);
        s.erase(cur);
        for (int i = 0; i < n; i++)
            s.insert(cur + a[i]);
    }

    std::cout << *std::begin(s);

    return 0;
}