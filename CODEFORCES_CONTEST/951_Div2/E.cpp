#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, d;
    std::cin >> n >> d;
    
    std::vector<std::pair<int, int>> a(n);
    for (auto &[x, y] : a)
        std::cin >> x >> y;
    
    auto dist = [&](int i, int j)
    {
        auto &[x1, y1] = a[i];
        auto &[x2, y2] = a[j];
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    };
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (dist(i, j) == d and dist(i, k) == d and dist(j, k) == d)
                {
                    print(a[i], a[j], a[k])
                    return;
                }
            }
        }
    }
    
    print(0, 0, 0)
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