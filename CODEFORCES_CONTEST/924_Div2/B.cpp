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

    std::sort(std::begin(a), std::end(a));
    a.erase(std::unique(std::begin(a), std::end(a)), std::end(a));

    int ans = 1;
    for (int i = 0; i < std::size(a); i++)
    {
        int cur = std::upper_bound(std::begin(a), std::end(a), a[i] + n - 1)
             - std::lower_bound(std::begin(a), std::end(a), a[i]);

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