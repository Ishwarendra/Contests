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

    for (int x = n;; x++)
    {
        i64 sq = 1LL * x * x;
        i64 sum = sq - 1LL * n * (n + 1) / 2;
        if (x + n - 1 < 0 or sum < 0)
            continue;

        std::vector<int> b(n);
        b[0] = (sum - (x - n + 1)) / n;
        b[n - 1] = b[0] + (x - n + 1);

        if (b[n - 1] > 1e9)
            continue;

        i64 rem = sum - b[0] - b[n - 1];
        if (rem < 0)
            continue;

        rem -= 1LL * (n - 2) * b[n - 1];

        if (rem > 0)
            continue;

        for (int i = 1; i < n - 1 and rem != 0; i++)
        {
            if (rem + (b[n - 1] - b[0]) <= 0)
                b[i] = b[0], rem += b[n - 1] - b[0];
            else
            {
                // rem + (b[n - 1] - num) = 0
                b[i] = b[n - 1] + rem;
                rem = 0;
            }
        }

        if (!std::is_sorted(std::begin(b), std::end(b)))
            continue;

        for (int i = 0; i < n; i++)
            std::cout << b[i] + i + 1 << " \n"[i == n - 1];

        return;
    }

    assert(false);
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