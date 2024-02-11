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
    int prev = 0;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    prev = a[n - 1];
    i64 ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] <= prev)
        {
            prev = a[i];
            continue;
        }

        if (prev == 1)
        {
            ans += a[i] - 1;
            continue;
        }

        int q = (a[i] + prev - 1) / prev;
        ans += q - 1;
        prev = a[i] / q;
        assert(prev != 0);
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