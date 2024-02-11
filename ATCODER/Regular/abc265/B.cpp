#include <bits/stdc++.h>

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

    int n, m, t;
    std::cin >> n >> m >> t;

    std::vector<int> a(n - 1);
    std::vector<std::pair<int, int>> bonus(m);
    for (int i = 0; i < n - 1; ++i)
        std::cin >> a[i];

    for (int i = 0; i < m; ++i)
        std::cin >> bonus[i].first >> bonus[i].second;

    std::sort(std::begin(bonus), std::end(bonus));

    i64 left = t;
    int pos = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (pos < m and bonus[pos].first == i + 1)
            left += bonus[pos++].second;
        
        left -= a[i];

        if (left <= 0)
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";

    return 0;
}