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
    std::cin >> n;

    std::multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m.emplace(x);
    }

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    auto inv = [&](int x)
    {
        int res = 0;
        for (int i = 0; i < 31; i++)
        {
            if (!getBit(x, i))
                res |= 1 << i;
        }

        return res;
    };

    int ans = 0;
    while (!m.empty())
    {
        auto x = *std::begin(m);
        m.erase(std::begin(m));
        ans++;

        auto it = m.find(std::abs(inv(x)));
        if (it != std::end(m))
            m.erase(it);
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