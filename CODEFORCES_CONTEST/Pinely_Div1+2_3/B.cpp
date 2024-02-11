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

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    auto getBit = [&](i64 x, int pos) { return x >> pos & 1LL; };
    for (int bit = 0; bit <= std::__lg(i64(2e17)); bit++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += getBit(a[i], bit);

        if (cnt == n or cnt == 0)
            continue;
        else
        {
            i64 k = (1LL << (bit + 1));
            std::set<i64> s;
            for (int i = 0; i < n; i++)
                s.emplace(a[i] % k);

            print(a, k)
            assert(std::size(s) == 2);
            std::cout << k << "\n";
            return;
        }
    }

    assert(false);
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