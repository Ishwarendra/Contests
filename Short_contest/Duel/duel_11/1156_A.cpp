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

    i64 ans = 0;
    const int circle = 1;
    const int triangle = 2;
    const int square = 3;

    std::set<std::pair<int, int>> infinite;
    infinite.emplace(triangle, square);
    infinite.emplace(square, triangle);

    for (int i = 1; i < n; i++)
    {
        if (infinite.count({a[i - 1], a[i]}))
        {
            std::cout << "Infinite";
            return 0;
        }

        if (a[i - 1] == triangle)
            ans += 3;
        else if (a[i - 1] == circle)
        {
            if (a[i] == square)
                ans += 4;
            else
                ans += 3;
        }
        else if (a[i - 1] == square)
            ans += 4;

        if (i - 2 >= 0 and a[i - 2] == square and a[i - 1] == circle and a[i] == triangle)
            ans--;
    }

    std::cout << "Finite\n" << ans;

    return 0;
}