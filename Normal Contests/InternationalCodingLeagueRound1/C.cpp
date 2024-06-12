#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)
        std::cin >> a[i][0];
    for (int i = 0; i < n; i++)
        std::cin >> a[i][1];

    std::sort(std::begin(a), std::end(a));
    int ans = n - 1;
    std::map<int, int> m;
    for (auto &[_, c] : a)
        m[c]++;

    for (int i = 0; i <= std::min(n - 1, k); i++)
    {
        auto [min, c] = a[i];
        int newK = k - i;
        int rem = n - i - newK - m[c];
        
        ans = std::min(ans, std::max(0, rem));
        m[c]--;
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