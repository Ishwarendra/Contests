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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::set<i64> sq;
    i64 x = 0;
    while (x * x <= 2e9)
        sq.emplace(x * x), x++;

    std::vector<int> ps(n);
    for (int i = 0; i < n; i++)
        ps[i] = sq.count(a[i]);
    
    std::multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        if (!sq.count(a[i]))
        {
            auto it = sq.lower_bound(a[i]);
            i64 cost = std::abs(*it - a[i]);

            if (it != std::begin(sq))
            {
                it--;
                cost = std::min(cost, std::abs(*it - a[i]));
            }

            m.emplace(cost);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += ps[i];

    if (cnt >= n / 2)
    {
        std::sort(std::rbegin(a), std::rend(a));
        int need = cnt - n / 2;
        int ans = 0;
        for (int i = 0, pos = 0; i < n and pos < need; i++)
        {
            if (!sq.count(a[i]))
                continue;

            pos++;
            ans += 1 + (a[i] == 0);
        }

        std::cout << ans;
    }
    else
    {
        int need = n / 2 - cnt;
        i64 ans = 0;

        while (need--)
        {
            ans += *std::begin(m);
            m.erase(std::begin(m));
        }

        std::cout << ans;
    }
    
    return 0;
}