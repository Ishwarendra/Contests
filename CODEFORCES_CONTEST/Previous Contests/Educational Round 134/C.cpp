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

    std::vector<int> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    for (int i = 0; i < n; i++)
        d[i] = b[i] - a[i];

    std::sort(std::begin(d), std::end(d));

    for (int i = 0; i < n; i++)
    {
        int min = *std::lower_bound(std::begin(b), std::end(b), a[i]);
        min -= a[i];
        std::cout << min << " \n"[i == n - 1];
    }

    std::vector<int> max(n);
    max[n - 1] = b[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        // next_ele of a > cur_ele of b then no choice except self
        if (a[i + 1] > b[i])
            max[i] = b[i];
        else
            max[i] = max[i + 1];
    }

    for (int i = 0; i < n; i++)
        std::cout << max[i] - a[i] << " \n"[i == n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}