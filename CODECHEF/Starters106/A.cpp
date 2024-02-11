#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] &= 1;
    }

    int cnt = 0;
    for (int i = 0; i < k - 1; i++)
        cnt += a[i];

    int ans = 0;
    for (int i = k - 1; i < n; i++)
    {
        cnt += a[i];
        ans += cnt > 0;
        cnt -= a[i - k + 1];
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