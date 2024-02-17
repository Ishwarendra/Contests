#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    i64 ans = 0;
    for (int i = 2 * n - 2; i >= 0; i -= 2)
        ans += a[i];
    
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