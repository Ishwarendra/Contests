#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    int ans = 1e9;
    {
        int ans1 = 0;
        int x = a, y = b;
        while (x % y)
            ans1++, x--, y++;

        if (x > 0)
            ans = ans1;
    }
    {
        int ans2 = 0;
        int x = a, y = b;
        while (x % y)
            x++, y--, ans2++;

        if (y > 0)
            ans = std::min(ans, ans2);
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