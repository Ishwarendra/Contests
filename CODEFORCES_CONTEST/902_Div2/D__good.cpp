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
    
    int n;
    std::cin >> n;

    i64 ans = 0;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    std::map<int, int> m;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        std::vector<int> ok(n + 1);
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
                ok[i + 1] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            if (ok[i])
            {
                for (int j = i; j <= n; j += i)
                    ok[j] = 1;
            }
        }

        int max = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ok[i])
                max = std::max(max, a[i]);
        }
        
        m[max]++;
        ans += max;
    }

    print(m)
    std::cout << ans % 998244353;
    
    return 0;
}