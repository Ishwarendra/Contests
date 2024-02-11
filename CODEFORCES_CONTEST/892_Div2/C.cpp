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

    auto get = [&](int max_id, int max) -> i64
    {
        i64 p = 1LL * max_id * max;
        std::set<int> s;
        for (int i = 1; i <= n; i++)
            s.emplace(i);
        s.erase(max);

        i64 ans = 0;

        for (int i = n; i >= 1; i--)
        {
            if (i == max_id)
                continue;

            auto it = s.upper_bound(p / i);
            if (it == std::begin(s))
                return 0;

            it = std::prev(it);
            ans += 1LL * i * (*it);
            s.erase(it);
        }

        return ans;
    };

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 1; x <= n; x++)
            ans = std::max(ans, get(i, x));
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