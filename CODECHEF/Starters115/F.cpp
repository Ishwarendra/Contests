#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    auto get = [&]()
    {
        i64 s = sum;
        int min = a.back();
        for (int i = n - 2; i >= 0; i--)
        {
            s -= std::min(min, a[i]);
            min -= std::min(min, a[i]);
            min = std::min(min, a[i]);

            if (min == 0)
                break;
        }

        std::cout << s << "\n";
    };

    get();
    while (q--)
    {
        int id, x;
        std::cin >> id >> x;
        id--;
        sum -= a[id];
        a[id] = x;
        sum += a[id];

        get();
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