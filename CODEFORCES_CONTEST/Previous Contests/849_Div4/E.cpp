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

    constexpr int inf = 1e9;
    int max = -inf, cnt = 0, zero = 0;
    int min = inf;

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            max = std::max(max, a[i]), cnt++;
        else
        {
            zero |= (a[i] == 0);
            min = std::min(min, a[i]);
        }

        a[i] = std::abs(a[i]);
        ans += a[i];
    }

    if (cnt % 2 and !zero and max != inf)
    {
        if (std::abs(min) < std::abs(max))
            ans -= 2 * min;
        else
            ans += 2 * max;
    }

    std::cout << ans << '\n';
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