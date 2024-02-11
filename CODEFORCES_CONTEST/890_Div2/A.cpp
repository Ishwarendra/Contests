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

    int ans = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            ans = std::max(ans, a[i]);
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