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
    std::cin >> n;

    std::map<int, std::multiset<int, std::greater<>>> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        m[x].emplace(y);
    }

    i64 ans = 0;
    for (auto &[x, p] : m)
    {
        int cnt = 0;
        for (auto it = std::begin(p); it != std::end(p) and cnt < x; it++)
        {
            ans += *it;
            cnt++;
        }
    }

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