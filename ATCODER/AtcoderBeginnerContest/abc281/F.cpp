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

    auto getBit = [&](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    auto f = [&](auto f, auto a, auto bit)
    {
        if (bit == -1)
            return 0;

        std::vector<int> set, unset;
        for (int i = 0; i < std::size(a); i++)
        {
            if (getBit(a[i], bit))
                set.emplace_back(a[i]);
            else
                unset.emplace_back(a[i]);
        }

        if (set.empty())
            return f(f, unset, bit - 1);
        else if (unset.empty())
            return f(f, set, bit - 1);
        else
            return std::min(f(f, set, bit - 1), f(f, unset, bit - 1)) | (1 << bit);
    };

    std::cout << f(f, a, 30);
    
    return 0;
}