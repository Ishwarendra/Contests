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

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    auto work = [&](auto &a, auto &b)
    {
        std::map<i64, bool> d;
        d[0] = true;
        for (int i = 1; i < std::size(a); i++)
        {
            if (i < std::size(b))
            {
                if (d.contains(a[i] - b[i]))
                    return true;
            }

            if (d.contains(a[i] - b[i - 1]))
                return true;

            d[a[i] - b[i]] = true;
        }

        return false;
    };

    std::vector<i64> a(1), b(1);
    for (int i = 0; i < n; i++)
    {
        auto &p = i % 2 ? b : a;
        p.emplace_back(p.back() + arr[i]);
    }

    bool ans = work(a, b);
    a.clear();
    b.clear();
    a.emplace_back(0);
    b.emplace_back(0);

    for (int i = 1; i < n; i++)
    {
        auto &p = i % 2 ? a : b;
        p.emplace_back(p.back() + arr[i]);
    }

    ans = ans || work(a, b);
    std::cout << (ans ? "YES\n" : "NO\n");
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