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
    std::sort(std::rbegin(b), std::rend(b));

    auto c = a;
    std::reverse(std::begin(c), std::end(c));
    std::vector<int> ans = c;
    auto work = [&](int max_id)
    {
        if (max_id > n)
            return;

        for (int i = 0; i < max_id; i++)
        {
            b.clear();
            for (int j = max_id; j < n; j++)
                b.emplace_back(a[j]);
            for (int j = max_id - 1; j >= i; j--)
                b.emplace_back(a[j]);
            for (int j = 0; j < i; j++)
                b.emplace_back(a[j]);

            assert(std::size(b) == n);
            ans = std::max(ans, b);
        }
    };
    int max_id = std::max_element(std::begin(a), std::end(a)) - std::begin(a);
    work(max_id);
    work(max_id + 1);

    int f = std::find(std::begin(a), std::end(a), n - 1) - std::begin(a);
    work(f);
    work(f + 1);

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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