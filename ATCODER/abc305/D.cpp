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

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
        std::cin >> p[i];

    std::vector<int> sum(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2)
            sum[i] = p[i + 1] - p[i];
    }

    for (int i = 1; i < n - 1; i++)
        sum[i] += sum[i - 1];

    auto get = [&](int l, int r) 
    {
        if (r < l)
            return 0;

        return sum[r] - (l > 0 ? sum[l - 1] : 0);
    };

    int q;
    std::cin >> q;

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        int ans = 0;

        auto it = std::upper_bound(std::begin(p), std::end(p), l) - std::begin(p);
        if (it == n)
            std::cout << "0\n";
        else
        {
            if (it % 2 == 0)
                ans += p[it] - l;

            int itr = std::upper_bound(std::begin(p), std::end(p), r) - std::begin(p) - 1;
            
            if (itr < it)
            {
                std::cout << (it % 2 == 0 ? r - l : 0) << "\n";
                continue;
            }
            if (itr % 2)
                ans += r - p[itr];

            ans += get(it, itr - 1);
            std::cout << ans << "\n";
        }
    }

    return 0;
}