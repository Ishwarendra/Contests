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

    int n, t;
    std::cin >> n >> t;

    std::vector<std::vector<double>> a(n + 1, std::vector<double>(n + 1));
    int ans = 0;

    a[0][0] = t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (a[i][j] >= 1)
            {
                a[i + 1][j] += (a[i][j] - 1) / 2;
                a[i + 1][j + 1] += (a[i][j] - 1) / 2;
                ans++;
            }
        }
    }

    print(a)

    std::cout << ans;

    return 0;
}