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
        std::cin >> a[i];

    if (a[0] != 1)
    {
        std::cout << "1\n";
        return;
    }

    i64 x = 1;
    for (int i = 1; i < n and k > 0; i++)
    {   
        int d = i;

        i64 have = (a[i] - x + d - 1) / d - 1;
        assert(have >= 0 and x <= a[i]);

        if (have >= k)
        {
            std::cout << x + 1LL * k * d << "\n";
            return;
        }

        k -= have;
        x = x + have * d;
    }

    std::cout << x + 1LL * k * n << "\n";
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