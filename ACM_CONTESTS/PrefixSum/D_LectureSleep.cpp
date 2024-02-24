#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> t(n);
    for (int i = 0; i < n; i++)
        std::cin >> t[i];

    // prefix sum to get how many theorem he can see if 
    // we don't use any spell to keep him awake
    std::vector<i64> p(n);
    for (int i = 0; i < n; i++)
        p[i] = (i ? p[i - 1] : 0) + t[i] * a[i];

    // total theorem, will help to calc theorem count
    // when we use our spell
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    i64 ans = p.back();
    k--;
    for (int i = 0; i + k < n; i++)
    {
        i64 cur = 0;

        // 0 to i - 1 no spell
        if (i - 1 >= 0)
            cur += p[i - 1];

        // i + k + 1 to n no spell
        cur += p.back() - p[i + k];

        // i to i + k no spell
        cur += a[i + k] - (i ? a[i - 1] : 0);

        ans = std::max(ans, cur);
    }

    std::cout << ans;

    return 0;
}