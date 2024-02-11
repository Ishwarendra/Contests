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
    
    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] > t)
                break;

            if (a[i] == a[j])
                continue;

            int r = std::upper_bound(std::begin(a), std::end(a), t - a[i] - a[j]) - std::begin(a);
            r--;
            int l = std::upper_bound(std::begin(a), std::end(a), a[j]) - std::begin(a);

            ans += std::max(0, r - l + 1);
        }
    }
    
    std::cout << ans;

    return 0;
}