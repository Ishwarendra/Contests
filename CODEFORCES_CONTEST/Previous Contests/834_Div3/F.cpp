#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, p;
    std::cin >> n >> p;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto make_unique = [&](auto & x)
    {
        std::sort(std::begin(x), std::end(x));
        x.erase(std::unique(std::begin(x), std::end(x)), std::end(x));
    };

    auto digit = a;
    make_unique(digit);

    auto id = std::find(std::begin(digit), std::end(digit), a.back()) - std::begin(digit);
    auto after = p - a.back() - (std::ssize(a) - id);
    auto before = a.back() - id;

    i64 ans = 0;
    if (before == 0)
    {
        // find biggest missing number \in [a.back(), p - 1]
        int count = 0;
        for (int i = p - 1; i >= a.back(); i--, count++)
        {
            if (!std::binary_search(std::begin(digit), std::end(digit), i))
            {
                ans = i - a.back();
                break;
            }
        }
    }
    else
    {
        ans += p - a.back();
        std::vector<int> b;

        b.emplace_back(0);
        int found = 0;
        for (int i = std::ssize(a) - 2; i >= 0; i--)
        {
            if (a[i] < p - 1)
            {
                b.emplace_back(a[i] + 1);
                found = 1;
                break;
            }
        }

        if (!found)
            b.emplace_back(1);

        for (auto ele : b)
            digit.emplace_back(ele);

        make_unique(digit);
        for (int i = a.back() - 1; i >= 0; i--)
        {
            if (!std::binary_search(std::begin(digit), std::end(digit), i))
            {
                ans += i;
                break;
            }
        }
    }

    std::cout << ans << "\n";
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