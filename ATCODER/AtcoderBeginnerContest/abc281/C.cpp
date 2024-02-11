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
    i64 t;
    std::cin >> n >> t;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    // for (int i = 1; i < n; i++)
    //     a[i] += a[i - 1];

    i64 tot = std::accumulate(std::begin(a), std::end(a), 0LL);
    t %= tot;

    int i;
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        if (t >= a[i])
            t -= a[i];
        else
        {
            ans = t;
            break;
        }
    }

    std::cout << i + 1 << " " << ans;
    
    return 0;
}