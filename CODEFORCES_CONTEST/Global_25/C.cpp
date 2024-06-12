#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    i64 ans = 0, bought = 0;
    for (int i = 0; i < n; i++)
    {
        auto need = k - bought;
        if (need >= m)
        {
            ans += 1LL * m * a[i] + bought * m; 
            bought += m;
        }
        else
        {
            ans += 1LL * need * a[i] + (bought) * need;
            bought += need;
            break;
        }
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