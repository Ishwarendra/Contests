#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int M = 60;

void solve()
{
    i64 n, x;
    std::cin >> n >> x;

    if (n == x)
    {
        std::cout << n << "\n";
        return;
    }
    auto getBit = [&](auto num, auto pos) { return (num >> pos) & 1LL; };

    for (int i = 0; i < M; i++)
    {
        if (!getBit(n, i) and getBit(x, i))
        {
            std::cout << "-1\n";
            return;
        }
    }

    auto zeroAfter = [&](auto &num, auto pos)
    {
        for (int i = pos - 1; i >= 0; i--)
        {
            if (getBit(num, i))
                num ^= (1LL << i);
        }
    };

    i64 max = n, min = (1LL << 62);
    for (int i = 0; i < M; i++)
    {
        if (!getBit(n, i))
            continue;

        if (!getBit(x, i))
        {
            max = std::max(max, n + (1 << (i + 1)));
            zeroAfter(max, i);
        }
        else
        {
            min = std::min(min, n + (1 << (i + 1)));
            zeroAfter(min, i);
        }
    }

    if (max < min)
        std::cout << max << "\n";
    else
        std::cout << "-1\n";
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