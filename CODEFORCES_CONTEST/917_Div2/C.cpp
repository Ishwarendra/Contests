#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, d;
    std::cin >> n >> k >> d;

    std::vector<int> a(n), b(k);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < k; i++)
        std::cin >> b[i];

    int ans = 0;
    for (int i = 0; i < std::min(n * 2 + 2, d); i++)
    {
        int cur = 0;
        for (int j = 0; j < n; j++)
            cur += a[j] == j + 1;

        for (int j = 0; j < b[i % k]; j++)
            a[j]++;

        ans = std::max(ans, cur + std::max(0, d - i - 1) / 2);
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