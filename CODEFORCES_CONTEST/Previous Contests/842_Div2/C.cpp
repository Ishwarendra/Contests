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

    std::set<int> first, second;
    std::vector<int> p(n), q(n);
    int possible = 1;

    for (int i = 1; i <= n; i++)
        first.emplace(i), second.emplace(i);

    for (int i = 0; i < n; i++)
    {
        if (first.count(a[i]))
            p[i] = a[i], first.erase(a[i]);
        else if (second.count(a[i]))
            q[i] = a[i], second.erase(a[i]);
        else
            possible = 0;
    }

    if (!possible)
        std::cout << "NO\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            auto &x = (p[i] == 0 ? first : second);
            auto &c = (p[i] == 0 ? p : q);
            auto &d = (p[i] == 0 ? q : p);

            auto it = x.upper_bound(d[i]);
            if (it == std::begin(x))
            {
                std::cout << "NO\n";
                return;
            }

            it--;
            c[i] = *it;
            x.erase(it);
        }

        std::cout << "YES\n";
        for (int i = 0; i < n; i++)
            std::cout << p[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; i++)
            std::cout << q[i] << " \n"[i == n - 1];
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