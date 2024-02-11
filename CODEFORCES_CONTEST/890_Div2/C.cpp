#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int max = *std::max_element(std::begin(a), std::end(a));
    int left = max, right = max + n;
    int ans = max;

    auto good = [&](int mid) -> bool
    {
        if (max >= mid)
            return true;

        auto f = [&](auto self, int id, int x, std::vector<int> &b) -> i64
        {
            i64 op = 0;

            if (b[id] >= x)
                return op;

            if (id == n - 1)
                return i64(1e18);

            op += self(self, id + 1, x - 1, b) + std::max(0, x - b[id]);
            return op;
        };

        for (int i = 0; i < n - 1; i++)
        {
            auto b = a;
            i64 op = f(f, i, mid, b);

            if (op > k)
                continue;

            if (mid == 8)
                print(op)
            return true;
        }

        return false;
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
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