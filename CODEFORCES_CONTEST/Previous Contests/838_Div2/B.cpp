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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int max_id = std::max_element(std::begin(a), std::end(a)) - std::begin(a);
    int max = a[max_id];

    int num = 1;
    while (num < max)
        num <<= 1;

    max = num;

    auto get = [&](int x)
    {
        for (int i = 0; i <= 30; i++)
        {
            int L = max >> (i + 1);
            int R = max >> i;

            if (L <= x and x <= R)
                return i;
        }

        return 0;
    };

    std::cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int p = get(a[i]);
        std::cout << i + 1 << " " << (max >> p) - a[i] << "\n";

        a[i] = (max >> p);
    }
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