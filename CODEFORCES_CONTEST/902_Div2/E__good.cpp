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

    if (n == 1)
    {
        std::cout << -1;
        return 0;
    }

    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (__builtin_popcount(mask) < (n + 1) / 2)
            continue;

        std::vector<int> uncircle;
        std::map<int, int> circle;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
                uncircle.emplace_back(a[i]);
            else
                circle[i + 1]++;
        }

        int ok = 1;
        for (auto x : uncircle)
        {
            if (!circle.contains(x))
            {
                ok = 0;
                break;
            }

            if (circle[x] == 0)
            {
                continue;
            }
            circle[x]--;
        }

        for (auto [p, f] : circle)
            ok &= f == 0;

        if (ok)
        {
            std::cout << "YES";
            return 0;
        }
    }

    std::cout << "NO";
    
    return 0;
}