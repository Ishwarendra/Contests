#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int M = 31;

int getBit(int x, int pos) { return x >> pos & 1; }

void solve()
{
    int n, x;
    std::cin >> n >> x;
    x++;

    std::vector a(n, 0), p(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        p[i] = (i ? p[i - 1] : 0) ^ a[i];
    }

    int ans = -1;
    auto xr = [&](int l, int r)
    {
        return p[r] ^ (l ? p[l - 1] : 0);
    };

    if (p[n - 1] >= x)
    {
        std::cout << "-1\n";
        return;
    }

    for (int b = M - 1; b >= 0; b--)
    {
        if (!getBit(x, b))
            continue;

        // b-th bit zero. Same as x behind it. Anything after.
        std::set<int> options;
        for (int i = 0; i < n - 1; i++)
            options.emplace(i);

        for (int i = 0; i < n - 1; i++)
        {
            if (getBit(p[i], b))
                options.erase(i);
        }

        for (int pos = M - 1; pos > b; pos--)
        {
            std::vector<int> del;
            for (int i : options)
            {
                if (getBit(p[i], pos) > getBit(x, pos))
                    del.emplace_back(i);
            }

            for (auto y : del)
                options.erase(y);
        }

        options.emplace(n - 1);
        int xr = 0;
        for (int i : options)
            xr |= p[i];

        int sz = std::size(options);
        if (xr < x)
            ans = std::max(ans, sz);
    } 

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