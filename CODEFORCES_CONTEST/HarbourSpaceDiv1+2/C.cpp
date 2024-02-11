#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x;
    std::cin >> x;

    std::vector<int> ans;
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    const int p = std::__lg(x);
    int m = 1 << p;
    int d = x - m;

    auto work = [&](int d)
    {
        for (int i = 0; i < 30; i++)
        {
            if (getBit(d, i))
            {
                d -= 1 << i;
                x -= 1 << i;
                ans.emplace_back(x);
            }
        }
    };

    ans.emplace_back(x);

    if (d > 0)
        work(d);
    
    assert(x == m);
    for (int i = 30; i > 0; i--)
    {
        if (getBit(m, i))
        {
            ans.emplace_back(m / 2);
            m >>= 1;
        }
    }

    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::size(ans); i++)
        std::cout << ans[i] << " \n"[i + 1 == std::size(ans)];
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