#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::vector<int> aa(3);
    std::cin >> aa[0] >> aa[1];

    aa[2] = aa[0] ^ aa[1];
    std::sort(std::begin(aa), std::end(aa));

    auto valid = [&](int x, int y, int z)
    {
        int cnt = x % 2 + y % 2 + z % 2;
        return x > 0 and y > 0 and z > 0 and cnt == 2;
    };

    // case-1: a = 2
    int a = 2, b = aa[0] ^ a, c = aa[2] ^ a;
    if (valid(a, b, c))
    {
        std::vector<int> ans{a, b, c};
        std::sort(std::begin(ans), std::end(ans));

        for (int i = 0; i < 3; ++i)
            std::cout << ans[i] << " \n"[i == 2];

        return;
    }

    b = 2, a = aa[0] ^ b, c = aa[2] ^ a;
    if (valid(a, b, c))
    {
        std::vector<int> ans{a, b, c};
        std::sort(std::begin(ans), std::end(ans));

        for (int i = 0; i < 3; ++i)
            std::cout << ans[i] << " \n"[i == 2];

        return;
    }

    c = 2, a = aa[2] ^ c, b = aa[0] ^ a;
    if (valid(a, b, c))
    {
        std::vector<int> ans{a, b, c};
        std::sort(std::begin(ans), std::end(ans));

        for (int i = 0; i < 3; ++i)
            std::cout << ans[i] << " \n"[i == 2];

        return;
    }
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