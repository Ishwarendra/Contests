#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector a(n + 1, std::vector(m + 1, 0));
    std::vector pref(n + 1, std::vector<i64>(m + 1));
    i64 sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
            sum += a[i][j];
        }
    }

    if (sum < k + 1)
    {
        std::cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }

    auto get = [&](int from_row, int from_col, int to_row, int to_col)
    {
        return pref[to_row][to_col] - pref[from_row - 1][to_col] 
                    - pref[to_row][from_col - 1] + pref[from_row - 1][from_col - 1];
    };

    auto good = [&](int d)
    {
        auto possible = [&](int i, int j) -> int
        {
            if (a[i][j] == 0)
                return 0;
            
            int from_row = std::max(1, i - d);
            int from_col = std::max(1, j - d);

            int to_row = std::min(n, i + d);
            int to_col = std::min(m, j + d);

            return get(from_row, from_col, to_row, to_col) >= k + 1;
        };

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                ans |= possible(i, j);
        }

        return ans;
    };

    int left = 0, right = std::max(n, m);
    int ans = -1;
    while (left <= right)
    {
        auto mid = (left + right) / 2;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
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