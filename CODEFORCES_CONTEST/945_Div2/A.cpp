#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::multiset<int> m;
    for (int i = 0; i < 3; i++)
    {
        int x;
        std::cin >> x;
        if (x > 0)
            m.emplace(x);
    }
    
    int ans = 0;
    while (std::size(m) > 1)
    {
        int max1 = *std::prev(std::end(m));
        m.erase(std::prev(std::end(m)));
        int max2 = *std::prev(std::end(m));
        m.erase(std::prev(std::end(m)));
        
        max1--, max2--, ans++;
        if (max1)
            m.emplace(max1);
        if (max2)
            m.emplace(max2);
    }
    
    if (std::size(m) == 1 and *std::begin(m) % 2)
        std::cout << -1 << "\n";
    else
        std::cout << ans << '\n';
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