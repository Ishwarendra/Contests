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

    i64 ans = 0;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;

        odd += a % 2;
        even += a % 2 == 0;
        ans += a;

        int sub = odd / 3;
        if (odd % 3 == 1 and i != 0)
            sub++;

        std::cout << ans - sub << " \n"[i == n - 1];
    }
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