#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1, -1);
    i64 ans = 0;
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        if (i and a[i] != a[i - 1])
            ans += 1LL * i * (n - i);
    }

    ans += 1LL * n * (n + 1) / 2;

    while (m--)
    {
        int i, x;
        std::cin >> i >> x;
        i--;

        if (i + 1 >= n or a[i + 1] != a[i])
            ans -= 1LL * (i + 1) * (n - (i + 1));
        if (i - 1 < 0 or a[i - 1] != a[i])
            ans -= 1LL * i * (n - i);

        if (i + 1 >= n or a[i + 1] != x)
            ans += 1LL * (i + 1) * (n - (i + 1));
        if (i - 1 < 0 or a[i - 1] != x)
            ans += 1LL * i * (n - i);

        std::cout << ans << "\n";
        a[i] = x;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    
    while (t--)
        solve();
    
    return 0;
}