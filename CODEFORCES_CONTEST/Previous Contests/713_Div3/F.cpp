#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9 + 10;

void solve()
{
    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n), b(n, inf);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    for (int i = 0; i < n - 1; ++i)
        std::cin >> b[i];

    i64 ans = (c + a[0] - 1) / a[0];
    std::vector<i64> extra(n);
    i64 prev_days = 0;

    for (int i = 1; i < n; ++i)
    {
        extra[i] = (b[i - 1] - extra[i - 1] + a[i - 1] - 1) / a[i - 1];
        prev_days += std::max(0LL, extra[i]) + 1;

        extra[i] = extra[i] * a[i - 1] - (b[i - 1] - extra[i - 1]);
        extra[i] = std::max(0LL, extra[i]);

        i64 cur_ans = (c - extra[i] + a[i] - 1) / a[i];
        cur_ans += prev_days;
        cur_ans = std::max(0LL, cur_ans);

        ans = std::min(ans, cur_ans);
    }
    
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