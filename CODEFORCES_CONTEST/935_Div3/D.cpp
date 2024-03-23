#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; i++)
    {
        int b;
        std::cin >> b;
        s[i] = std::min(a[i], b);
    }

    for (int i = n - 1; i >= 0; i--)
        s[i] += s[i + 1];

    i64 ans = inf;
    for (int i = 0; i < m; i++)
        ans = std::min(ans, s[i + 1] + a[i]);

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