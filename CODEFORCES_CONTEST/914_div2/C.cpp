#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct DS
{
    std::multiset<i64> m, d;
    void add(i64 x)
    {
        auto it = m.insert(x);

        auto prev = std::begin(m);
        auto next = prev;

        if (it != std::begin(m))
        {
            prev = std::prev(it);
            d.emplace(*it - *prev);
        }

        if (std::next(it) != std::end(m))
        {
            next = std::next(it);
            d.emplace(*next - *it);
        }

        if (it != std::begin(m) and std::next(it) != std::end(m))
            d.erase(d.find(*next - *prev));
    }

    void remove(i64 x)
    {
        auto it = m.find(x);

        auto prev = std::begin(m);
        auto next = prev;

        if (it != std::begin(m))
        {
            prev = std::prev(it);
            d.erase(d.find(*it - *prev));
        }

        if (std::next(it) != std::end(m))
        {
            next = std::next(it);
            d.erase(d.find(*next - *it));
        }

        if (it != std::begin(m) and std::next(it) != std::end(m))
            d.emplace(*next - *prev);

        m.erase(it);
    }
};

i64 brute(int n, std::vector<i64> &a)
{
    i64 ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            i64 del = std::abs(a[i] - a[j]);
            a.emplace_back(del);

            for (int k = 0; k <= n; k++)
            {
                for (int p = 0; p <= n; p++)
                {
                    if (k == p)
                        continue;

                    a.emplace_back(std::abs(a[k] - a[p]));
                    ans = std::min(ans, *std::min_element(std::begin(a), std::end(a)));
                    a.pop_back();
                }       
            }

            a.erase(std::find(std::begin(a), std::end(a), del));
        }
    }

    return ans;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    DS ds;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        i64 x;
        std::cin >> x;
        a[i] = x;
        ds.add(x);
    }

    if (k > 2)
    {
        std::cout << 0 << "\n";
        return;
    }

    if (k == 1)
    {
        i64 d = 2e18;
        for (int i = 0; i < n; i++)
        {
            d = std::min(d, a[i]);
            for (int j = i + 1; j < n; j++)
                d = std::min(d, std::abs(a[i] - a[j]));
        }

        std::cout << d << "\n";
        return;
    }

    i64 ans = 2e18;
    auto o = ds.m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            i64 d = std::abs(a[i] - a[j]);
            ds.add(d);
            ans = std::min({ans, *std::begin(ds.d), *std::begin(ds.m)});
            ds.remove(d);

            print(ds.m)
        }
    }

    std::cout << ans << "\n";
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