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
    i64 k;
    std::cin >> n >> k;

    std::deque<int> d;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        d.emplace_back(x);
    }

    int ans = 0;
    while (std::size(d) > 1)
    {
        auto f = d.front(), b = d.back();
        int min = std::min(f, b);
        if (k < min * 2LL - 1)
            break;

        d.pop_front();
        d.pop_back();

        f -= min, b -= min - 1;
        k -= 2 * min - 1;
        if (f > 0)
            d.emplace_front(f);
        else
            ans++;

        if (b > 0)
        {
            if (k > 0)
            {
                k--;
                b--;
            }
        }

        if (b > 0)
            d.emplace_back(b);
        else
            ans++;
    }

    if (std::size(d) == 1 and d.front() <= k)
        ans++;

    std::cout << ans << "\n";
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