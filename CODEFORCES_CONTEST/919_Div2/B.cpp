#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, x;
    std::cin >> n >> k >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int x_ = x;
    std::sort(std::begin(a), std::end(a));
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (x)
            ans -= a[i], x--;
        else
            ans += a[i];
    }

    x = x_;
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    auto sum = [&](int l, int r)
    {
        if (l > r or l < 0)
            return 0;

        return a[r] - (l ? a[l - 1] : 0);
    };

    for (int i = n - 1; i >= n - k; i--)
    {
        int cur = sum(0, i - x - 1) - sum(std::max(0, i - x), i - 1);
        ans = std::max(ans, cur);
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