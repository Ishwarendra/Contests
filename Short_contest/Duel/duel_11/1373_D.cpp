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

    i64 ans = 0;
    for (int i = 0; i < n; i += 2)
        ans += a[i];

    auto get = [&](int st)
    {
        i64 max = 0, cur = 0;
        int sgn = (st == 1 ? -1 : 1);
        for (int i = st; i + 1 < n; i += 2)
        {
            cur += sgn * (a[i + 1] - a[i]);
            max = std::max(max, cur);

            if (cur < 0)
                cur = 0;
        }

        return max;
    };    

    i64 max = std::max(get(0), get(1));
    std::cout << ans + max << "\n";
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