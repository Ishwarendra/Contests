#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> p(n + 1);
    p[1] = x;
    p[n] = 1;

    for (int i = 2; i < n; i++)
        p[i] = i;

    if (n % x != 0)
    {
        std::cout << "-1\n";
        return;
    }

    // 2 4 6 8 10 12
    // 12 4 6 8 10 1
    // could have given 12 to 6

    for (; x < n; )
    {
        int y = x + x;
        while (n % y)
            y += x;

        p[x] = y;
        x = y;
    }

    for (int i = 1; i <= n; i++)
        std::cout << p[i] << " \n"[i == n];
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