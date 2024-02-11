#include <bits/stdc++.h>

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

    std::vector<int> x(n), y(n), d(n);
    for (int i = 0; i < n; i++)
        std::cin >> x[i];

    for (int i = 0; i < n; i++)
    {
        std::cin >> y[i];
        d[i] = y[i] - x[i];
    }

    std::multiset<int> m(std::begin(d), std::end(d));
    int ans = 0;
    while (!m.empty())
    {
        auto cur = *std::begin(m);
        m.erase(std::begin(m));

        auto it = m.lower_bound(-cur);

        if (it != std::end(m))
        {
            m.erase(it);
            ans++;
        }
    }
c
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}