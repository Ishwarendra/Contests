#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    const int MOD = m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (n > m)
        std::cout << 0;
    else
    {
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                ans = 1LL * ans * std::abs(a[i] - a[j]) % MOD;
        }

        std::cout << ans;
    }

    return 0;
}