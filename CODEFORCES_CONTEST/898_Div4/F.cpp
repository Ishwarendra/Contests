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

    std::vector<int> a(n), h(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> h[i];

    int ans = a[0] <= k;
    i64 fruit = a[0] * (a[0] <= k);
    for (int i = 1, st = (ans == 0); i < n; i++)
    {
        int cur = 0;

        while (st < i and fruit + a[i] > k)
            fruit -= a[st++];
        if (h[i - 1] % h[i] == 0 and fruit + a[i] <= k)
            fruit += a[i];
        else 
        {
            if (a[i] > k)
                fruit = 0, st = i + 1;
            else
                fruit = a[i], st = i;
        }
        ans = std::max(ans, i - st + 1);
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