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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto closest = [&](int i)
    {
        if (i - 1 < 0)
            return i + 1;
        if (i + 1 >= n)
            return i - 1;

        if (std::abs(a[i] - a[i - 1]) > std::abs(a[i] - a[i + 1]))
            return i + 1;
        return i - 1;
    };

    std::vector<i64> back(n), front(n);
    for (int i = 1; i < n; i++)
    {
        if (closest(i - 1) == i)
            front[i] = front[i - 1] + 1;
        else
            front[i] = front[i - 1] + std::abs(a[i] - a[i - 1]); 
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (closest(i + 1) == i)
            back[i] = back[i + 1] + 1;
        else
            back[i] = back[i + 1] + std::abs(a[i] - a[i + 1]);
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;

        i64 ans = 0;
        if (x < y)
            ans = front[y] - front[x];
        else
            ans = back[y] - back[x];

        std::cout << ans << "\n";
    }
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