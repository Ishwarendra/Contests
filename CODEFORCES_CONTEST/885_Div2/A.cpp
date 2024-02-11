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

    int x, y;
    std::cin >> x >> y;

    std::vector<int> a(k), b(k);
    for (int i = 0; i < k; i++)
        std::cin >> a[i] >> b[i];

    int ok = 1;
    for (int i = 0; i < k; i++)
    {
        int d = std::abs(x - a[i] + y - b[i]);
        if (d % 2 == 0)
            ok = 0;
    }

    std::cout << (ok ? "YES\n" : "NO\n");
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