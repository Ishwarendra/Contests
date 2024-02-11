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

    std::multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m.emplace(x);
    }

    i64 x = 0;
    i64 ans = 0;
    while (std::size(m) > 1)
    {
        int max = *std::rbegin(m);
        int min = *std::begin(m);

        if (x + min >= max)
        {
            m.erase(m.find(max));
            ans++;

            ans += max - x;
            min -= (max - x);
            x = 0;

            m.erase(std::begin(m));

            if (min)
                m.emplace(min);
        }
        else
        {
            x += min, ans += min;
            m.erase(std::begin(m));
        }
    }

    if (!m.empty())
    {
        int max = *std::rbegin(m);
        i64 a = (max - x) / 2;
        print(m, max, a, x)
        ans += a;
        max -= a;

        x += a;
        max -= x;
        if (x)
            ans++;

        ans += max;
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