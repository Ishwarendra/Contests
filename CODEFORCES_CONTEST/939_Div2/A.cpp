#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int k, q;
    std::cin >> k >> q;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++)  
        std::cin >> a[i];

    auto get = [&](int x)
    {
        return std::upper_bound(std::begin(a), std::end(a), x) - std::begin(a);
    };

    while (q--)
    {
        int n;
        std::cin >> n;

        while (true)
        {
            int sub = get(n);
            n -= sub;
            if (sub == 0)
                break;
        }

        std::cout << n <<  " \n"[q == 0];
    }
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