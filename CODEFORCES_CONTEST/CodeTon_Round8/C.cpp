#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, sz, y;
    std::cin >> n >> sz >> y;

    std::vector<int> a(sz);
    for (int i = 0; i < sz; i++)  
    {
        std::cin >> a[i];
        a[i]--;
    }

    std::sort(std::begin(a), std::end(a));
    a.emplace_back(a.front());

    auto dist = [&](int i, int j)
    {
        return (j - i + n) % n;
    };

    int ans = 0;
    for (int i = 1; i <= sz; i++)
    {
        if (dist(a[i - 1], a[i]) == 2)
            ans++;
    }

    std::cout << ans + sz - 2 << "\n";
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