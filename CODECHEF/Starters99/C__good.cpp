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

    std::vector a(n, std::array<int, 2>());
    for (auto &[x, y] : a)
        std::cin >> x >> y;

    int ans = 1e9;
    std::vector<int> one, two;
    std::function<void(int)> f = [&](int id)
    {
        if (id == n)
        {
            if (one.empty() || two.empty())
                return;

            int max1 = *std::max_element(std::begin(one), std::end(one));
            int max2 = *std::max_element(std::begin(two), std::end(two));
            ans = std::min(ans, std::abs(max1 - max2));
            // if (max1 == max2)
            //     print(one, two)
            return;
        }

        one.emplace_back(a[id][0]);
        f(id + 1);
        one.pop_back();
        one.emplace_back(a[id][1]);
        f(id + 1);
        one.pop_back();

        two.emplace_back(a[id][0]);
        f(id + 1);
        two.pop_back();
        two.emplace_back(a[id][1]);
        f(id + 1);
        two.pop_back();        
    };

    f(0);
    std::cout << ans<< "\n";
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