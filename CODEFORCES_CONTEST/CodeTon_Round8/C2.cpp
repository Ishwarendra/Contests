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
        int d = (j - i + n) % n;
        if (d == 0)
            d = n;
        return d;
    };

    int ans = y + sz - 2;
    std::vector<int> d;
    for (int i = 1; i <= sz; i++)
    {
        int distance = dist(a[i - 1], a[i]);
        if (distance == 2)
        {
            ans++;
            continue;
        }

        if (distance % 2 == 0 and distance != 2)
            d.emplace_back(distance / 2 - 1);
    }

    std::sort(std::begin(d), std::end(d));
    d.emplace_back(n);
    for (int i = 0; i < std::size(d) and y; i++)
    {
        if (d[i] <= y)
            y -= d[i], ans += d[i] + 1;
        else
            ans += y, y = 0;
    }

    std::cout << std::min(ans, n - 2) << "\n";

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