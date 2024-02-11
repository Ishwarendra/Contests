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

    std::vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    i64 ans = 0;
    int min = pos[0], max = pos[0];
    for (int len = 1; len <= n; len++)
    {
        min = std::min(min, pos[(len - 1) / 2]);
        max = std::max(max, pos[(len - 1) / 2]);

        int left = std::max(0, max - len + 1);
        int right = std::min(min, n - len);
        print(len, left, right)

        ans += std::max(0, right - left + 1);
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