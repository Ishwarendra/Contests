#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int p10[7] {};

void solve()
{
    int A, B, C;
    i64 k;
    std::cin >> A >> B >> C >> k;

    auto get = [&](int x, int y, int z)
    {
        auto res = std::to_string(x) + ' ' + '+' + ' ' + std::to_string(y) + ' ';
        res += '=';
        res += ' ';
        res += std::to_string(z);
        return res;
    };

    for (int a = p10[A - 1]; a < p10[A]; a++)
    {
        std::array<int, 2> min{}, max{};
        min = {p10[B - 1], p10[C - 1] - a};
        max = {p10[B] - 1, p10[C] - 1 - a};

        int L = std::max({1, min[0], min[1]});
        int R = std::min(max[0], max[1]);
        int rank = std::max(0, R - L + 1);
        if (k <= rank)
        {
            std::cout << get(a, L + k - 1, a + L + k - 1) << "\n";
            return; 
        }

        k -= rank;
    }

    std::cout << "-1\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    p10[0] = 1;
    for (int i = 1; i < 7; i++)
        p10[i] = p10[i - 1] * 10;

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}