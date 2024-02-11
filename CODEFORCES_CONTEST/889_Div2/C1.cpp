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

    int min_id = std::min_element(std::begin(a), std::end(a)) - std::begin(a);
    int max_id = std::max_element(std::begin(a), std::end(a)) - std::begin(a);

    int neg = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        neg += a[i] < 0;
        pos += a[i] > 0;
    }

    std::vector<std::pair<int, int>> ans;

    auto get1 = [&]()
    {
        if (a[min_id] < 0 and std::abs(a[min_id]) > a[max_id])
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] > 0)
                    a[i] += a[min_id], ans.emplace_back(i, min_id);
            }

            assert(*std::max_element(std::begin(a), std::end(a)) <= 0);

            for (int i = n - 2; i >= 0; i--)
            {
                a[i] += a[i + 1];
                ans.emplace_back(i, i + 1);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] < 0)
                    a[i] += a[max_id], ans.emplace_back(i, max_id);
            }

            assert(*std::min_element(std::begin(a), std::end(a)) >= 0);

            for (int i = 1; i < n; i++)
            {
                a[i] += a[i - 1];
                ans.emplace_back(i, i - 1);
            }
        }
    };

    auto get2 = [&]()
    {

        if (neg > pos)
        {
            for (int i = 0; i < 5; i++)
            {
                a[min_id] += a[min_id];
                ans.emplace_back(min_id, min_id);
            }


            for (int i = 0; i < n; i++)
            {
                if (a[i] > 0)
                    a[i] += a[min_id], ans.emplace_back(i, min_id);
            }

            for (int i = n - 2; i >= 0; i--)
            {
                if (a[i] <= a[i + 1])
                    continue;

                a[i] += a[i + 1];
                ans.emplace_back(i, i + 1);
            }
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                a[max_id] += a[max_id];
                ans.emplace_back(max_id, max_id);
            }

            for (int i = 0; i < n; i++)
            {
                if (a[i] < 0)
                    a[i] += a[max_id], ans.emplace_back(i, max_id);
            }

            for (int i = 1; i < n; i++)
            {
                if (a[i] >= a[i - 1])
                    continue;

                a[i] += a[i - 1];
                ans.emplace_back(i, i - 1);
            }
        }
    };

    if (std::abs(neg - pos) <= 4)
        get1();
    else
        get2();

    std::cout << std::size(ans) << "\n";
    assert(std::size(ans) <= 31);
    for (auto &[l, r] : ans)
        std::cout << l + 1 << " " << r + 1 << "\n";

    assert(std::is_sorted(std::begin(a), std::end(a)));
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