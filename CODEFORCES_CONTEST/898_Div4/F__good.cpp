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

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            i64 sum = std::accumulate(std::begin(a) + i, std::begin(a) + j + 1, 0LL);
            int ok = sum <= k;

            for (int k = i + 1; k <= j; k++)
                if (h[k - 1] % h[k] != 0)
                    ok = 0;
            if (ok)
                ans = std::max(ans, j - i + 1);
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