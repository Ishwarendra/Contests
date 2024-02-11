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

    auto b = a;
    b.resize(std::unique(std::begin(b), std::end(b)) - std::begin(b));

    if (std::is_sorted(std::begin(a), std::end(a)))
    {
        std::cout << "0\n";
        return;
    }

    if (std::is_sorted(std::rbegin(a), std::rend(a)))
    {
        std::cout << int(1e9) << "\n";
        return;
    }

    int l = 0, r = 1e9;
    for (int i = 0; i < std::ssize(b) - 1; i++)
    {
        if (b[i] < b[i + 1])
        {
            int max = std::max((b[i] + b[i + 1]) / 2, b[i]);
            r = std::min(r, max);
        }
        else
            l = std::max(l, (b[i] + b[i + 1]) / 2);
    }

    if (l > r)
        std::cout << "-1\n";
    else
    {
        for (int x = l; x <= r; x++)
        {
            std::vector<int> c(n, 0);
            for (int i = 0; i < n; i++)
                c[i] = std::abs(a[i] - x);

            if (std::is_sorted(std::begin(c), std::end(c)))
            {
                std::cout << x << "\n";
                return;
            }
        }

        std::cout << "-1\n";
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