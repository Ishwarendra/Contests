#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    i64 x, y;
    std::cin >> n >> x >> y;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    a.emplace_back(1e18);

    int can = 0;
    for (int i = 0; i < n; i++)
    {
        if (x >= a[i])
        {
            can++;
            if (x + can == y)
            {
                std::cout << i + 1 << "\n";
                return;
            }
        }
        else
            can--;
    }
    
    if (can <= 0)
    {
        std::cout << "-1\n";
        return;
    }

    i64 ans = 0;
    for (int i = 0; i < n;)
    {
        i = std::upper_bound(std::begin(a), std::end(a), x) - std::begin(a);
        // +i and -(n - i) = i + i - n = 2 * i - n;

        i64 one = 2 * i - n;
        i64 for_y = one * (y - i - x) / can;
        i64 for_next = one * (a[i + 1] - x) / can;

        if (for_y <= for_next)
        {
            ans += for_y;
            break;
        }
        else
            ans += for_next;
    }

    print(ans, x, y)
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}