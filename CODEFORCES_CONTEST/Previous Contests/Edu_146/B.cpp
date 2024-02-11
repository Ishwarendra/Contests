#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<i64> sq;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    if (a < b)
        std::swap(a, b);

    i64 best = a + b;
    for (int max = 1; max < std::sqrt(a) + 3e4; max++)
    {
        i64 ans = max - 1;

        ans += (a / max) + (a % max != 0);
        ans += (b / max) + (b % max != 0);
        best = std::min(ans, best);
    }

    std::cout << best << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (i64 i = 1; i * i <= 1e9 + 10; i++)
        sq.emplace_back(i * i);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}