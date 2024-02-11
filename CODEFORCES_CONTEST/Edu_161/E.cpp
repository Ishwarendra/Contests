#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 x;
    std::cin >> x;
    x--;

    i64 have = 2;
    std::vector<int> a(1, 0);

    while (have * 2 <= x)
    {
        have *= 2;
        a.emplace_back(a.back() + 1);
    }

    x -= have;
    x++;
    int sz = std::size(a);

    while (x > 0)
    {
        int left = 0, right = sz - 1;
        int ans = 0;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if ((1LL << mid) <= x)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        a.emplace_back(a[ans]);
        x -= (1LL << ans);  

        if (x < 0)
        {
            std::cout << "-1\n";
            return;
        }
    }

    std::cout << std::size(a) << "\n";
    for (int i = 0; i < std::size(a); i++)
        std::cout << a[i] << " \n"[i + 1 == std::size(a)];
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