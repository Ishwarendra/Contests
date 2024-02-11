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

    std::vector<i64> suff(n);
    suff.back() = a.back();
    for (int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + a[i];

    i64 ans = 0;
    int len = 1;
    for (int i = 0; i < n; i++)
    {
        if (i and suff[i] > 0)
            ans += 1LL * (++len) * a[i];
        else
            ans += 1LL * (len) * a[i];
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