#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::pair<int, int>> range;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        range.emplace_back(a[i] + i + 1, a[i]);
    }

    std::sort(std::begin(range), std::end(range));
    int last = 1e9 + 1e5;
    int gmin = 1e9 + 1e5;

    while (!range.empty())
    {
        auto [max, min] = range.back();
        range.pop_back();
        gmin = std::min(min, gmin);

        if (last > max)
        {
            std::cout << max << " ";
            last = max;
        }
        else if (last <= max)
        {
            if (gmin < last)
                std::cout << (--last) << " ";
        }
    }

    std::cout << "\n";
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