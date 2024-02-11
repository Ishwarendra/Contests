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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int need = (i + k) / k;
        int have = 0;
        for (int j = 0; j < i; j++)
            have += a[j] == 1;

        if (have < need)
            a[i] = 1;

        have = 0;
        for (int j = 0; j < i; j++)
            have += a[n - j - 1] == 1;

        if (have < need)
            a[n - i - 1] = 1;
    }

    std::cout << std::accumulate(std::begin(a), std::end(a), 0) << "\n";
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