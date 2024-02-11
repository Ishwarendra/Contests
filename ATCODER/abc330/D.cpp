#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> row(n), col(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            row[i] += a[i][j] == 'o';
            col[j] += a[i][j] == 'o';
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int r = row[i];
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 'o')
                continue;

            r -= a[i][j] == 'o';
            col[j] -= a[i][j] == 'o';
            ans += 1LL * r * col[j];
            r += a[i][j] == 'o';
            col[j] += a[i][j] == 'o';
        }
    }

    std::cout << ans;

    return 0;
}